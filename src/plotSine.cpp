#include "../include/head.h"


int startCurses;
{

	initscr();
	curs_set(0);

	list<DataPoint> dataPoints = ingestJsonFile("DATA/Results/Output.json");

	double amplitude, period = 100, phaseShift;
	calculateSinewaveParams(dataPoints, amplitude, period, phaseShift);
	

	for (list<DataPoint>::iterator it = dataPoints.begin(); it != dataPoints.end(); it++)
	{
		it->value = calculateSinewave(amplitude, period, phaseShift, it->date);
	}
	

	plotData(dataPoints);
	

	mvprintw(0, 0, "Amplitude: %f", amplitude);
	mvprintw(1, 0, "Period: %f", period);
	mvprintw(2, 0, "Phase Shift: %f", phaseShift);
	

	refresh();
	

	getch();

	endwin();

	return &dataPoints;
}

void plotData(list<DataPoint> dataPoints)
{
	int x, y;
	double maxValue = 0, minValue = 0;

	for (list<DataPoint>::iterator it = dataPoints.begin(); it != dataPoints.end(); it++)
	{
		if (it->value > maxValue)
			maxValue = it->value;
		if (it->value < minValue)
			minValue = it->value;
	}

	for (list<DataPoint>::iterator it = dataPoints.begin(); it != dataPoints.end(); it++)
	{

		x = (it->date - dataPoints.begin()->date) * COLS / (dataPoints.rbegin()->date - dataPoints.begin()->date);
		y = (it->value - minValue) * LINES / (maxValue - minValue);
		

		mvaddch(LINES - y, x, '*');
	}
}


list<DataPoint> ingestJsonFile(string filename) 
{
	list<DataPoint> dataPoints;
	ifstream jsonFile;
	jsonFile.open(filename);

	if (jsonFile.is_open()) {
		Json::Value root;
		jsonFile >> root;

		for (int i = 0; i < root.size(); i++) {
			if (root[i]["sunspots"].asInt() != -1) {
				
				DataPoint dp;
				dp.date = root[i]["date"].asInt();
				dp.value = root[i]["sunspots"].asDouble();
				dataPoints.push_back(dp);
			}
		}
	}
	jsonFile.close();
	return dataPoints;
}



void calculateSinewaveParams(list<DataPoint> dataPoints, double& amplitude, double& period, double& phaseShift)
{
	double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	double x, y;

	for (list<DataPoint>::iterator it = dataPoints.begin(); it != dataPoints.end(); it++) {
		x = (it->date - dataPoints.begin()->date);
		y = it->value;
		
		a1 += x * y;
		b1 += x * x;
	}
	
	for (list<DataPoint>::iterator it = dataPoints.begin(); it != dataPoints.end(); it++) 
	{
		x = (it->date - dataPoints.begin()->date);
		y = sin(2 * M_PI * x / period);
		
		a2 += x * y;
		b2 += x * x;
	}
	// Calculate the amplitude and phase shift
	amplitude = (a1 * b2 - a2 * b1) / (b2 * b2 - b1 * b2);
	phaseShift = (a2 * b1 - a1 * b2) / (b2 * b2 - b1 * b2);
}

double calculateSinewave(double amplitude, double period, double phaseShift, int date)
{
	double sinewave = amplitude * sin(2 * M_PI * (date - phaseShift) / period);
	return sinewave;
}

