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

struct Edge
{
	int src, dest;
};

struct Graph
{
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

/* Function declarations */
void get_sine_osodial_wave_from_csv(char* filename);
void create_fourier_transform(float* sine_wave);
void display_sine_osodial_wave_on_ncurses(float* sine_wave);
void display_fourier_transform_on_wxwidgets(float* fourier_transform);


#endif // __HEADER_H__
// Path: src/header.h
