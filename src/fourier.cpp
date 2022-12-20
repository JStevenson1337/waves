#include "../include/head.h"



int plotFourier() 
{ 
 
	list<double> dataPoints; 
	dataPoints.push_back(0.5); 
	dataPoints.push_back(0.6); 
	dataPoints.push_back(0.7); 
	dataPoints.push_back(0.8); 


	list<double> fourierSeries; 
	fourierSeries = calculateFourierSeries(dataPoints); 


	vector<list<double>> data; 
	data.push_back(dataPoints); 
	data.push_back(fourierSeries); 

	wxChartViewer chartViewer; 
	chartViewer.showChart(data); 


	initscr(); 
	for (auto i : fourierSeries) 
		printw("%lf ", i); 
	refresh(); 
	endwin(); 


	string folderName = "FourierSeries"; 
	mkdir(folderName.c_str(), 0777); 

	string filename = folderName + "/" + 
					to_string(time(NULL)) + ".txt"; 


	ofstream file(filename.c_str()); 
	for (auto i : fourierSeries) 
		file << i << " "; 
	file.close(); 
	return 0; 
}


list<double> calculateFourierSeries(list<double> &dataPoints) 
{ 

	list<double> fourierSeries; 
	int size = dataPoints.size(); 


	for (int i = 0; i < size; i++) 
	{ 
		double sum = 0; 
		for (int k = 0; k < size; k++) 
		{ 
			sum += dataPoints.at(k) * 
				cos((2 * M_PI * i * k) / size); 
		} 
		fourierSeries.push_back(sum); 
	} 
	return fourierSeries; 
} 
