#ifndef __HEADER_H__
#define __HEADER_H__
#include <iostream>
#include <curses.h>
#include <stdlib.h>
#include <sys/random.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ncurses.h>
#include <stdio.h>
#include <math.h>
#include "wx/wx.h"

#define BUFFER 100;

/*
 * Sunspot data structure - Structure to pull data from the sunspot data file
 * @year - Year of the data
 * @day - Day of the data
 * @month - Month of the data
 * @numSunspots - Number of sunspots in the data
 * @return - None
 */
typedef struct SunspotData { 
	int year;
	int day; 
	int month; 
	int num_sunspots; 
}ss_data;

/*
 * Plot point structure - Structure to store 
 * coordinates to plot on a graph
 * @x - x coordinate of the point (jdn)
 * @y - y coordinate of the point (num_sunspots)
 * @return - None
 */
typedef struct plot_point {
	float x;
	float y;
} t_data_p;

/* Function declarations */
double DateConverter::dateToJulian(ss_data data);
double DateConverter::computeJulianDay(int year, int month, int day)
void create_fourier_transform(float* sine_wave);
void display_sine_osodial_wave_on_ncurses(float* sine_wave);
void display_fourier_transform_on_wxwidgets(float* fourier_transform);


#endif // __HEADER_H__
// Path: src/header.h
