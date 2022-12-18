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

int readCSV();
int initCurse();


#endif // __HEADER_H__
// Path: src/header.h
