#ifndef __HEAD_H__
#define __HEAD_H__

#include <ctime>
#include <fstream>
#include <ncurses.h>
#include <cmath>
#include <list>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <sstream>
#include <string>
#include <wx/wx.h>
#include <vector>

using namespace std;



struct DataPoint {
	int date;
	double value;
	
};

struct ChartData {
	vector<list<double>> data;
}view_t;

class JsonData {
public:
	JsonData();
	~JsonData();
	
	int parseDataFile(void);

private:
	std::ifstream inputFile;
	std::ofstream outputFile;
	Json::Value root;
	Json::Value outputArray;
};


/* ParseJSON */
int parseDataFile(void);

// /* PlotSine.cpp */
int startCurses;
void calculateSinewaveParams(list<DataPoint> dataPoints, double& amplitude, double& period, double& phaseShift);
double calculateSinewave(double amplitude, double period, double phaseShift, int date);
list<DataPoint> ingestJsonFile(string filename);
void plotData(list<DataPoint> dataPoints);

/* fourier.cpp */
int plotFourier;
list<double> calculateFourierSeries(list<double> &dataPoints);

#endif // __HEAD_H__

