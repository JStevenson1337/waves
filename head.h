#ifndef __HEAD_H__
#define __HEAD_H__

#include <ctime>
#include <fstream>
#include <ncurses.h>
#include <math.h>
#include <list>
#include <iostream> 
#include <json/json.h>
#include <jsoncpp/json/json.h>
#include <sstream>
#include <string>
#include <wxwidgets/wxwidgets.h> 
#include <vector> 

using namespace std;


struct DataPoint {
	int date;
	double value;
};



/* ParseJSON*/
int parseDataFile()

/* PlotSine.cpp*/
int startCurses();
void calculateSinewaveParams(list<DataPoint> dataPoints, double& amplitude, double& period, double& phaseShift);
double calculateSinewave(double amplitude, double period, double phaseShift, int date);
list<DataPoint> ingestJsonFile(string filename);
void plotData(list<DataPoint> dataPoints);

/* fourier.cpp*/
int plotFourier();
list<double> calculateFourierSeries(list<double> &dataPoints);

#endif // __HEAD_H__
// // Path: src/header.h
