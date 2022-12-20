#include "../include/header.h"

/*
 * display_sine_osodial_wave_on_ncurses - displays a
 * sine wave on ncurses
 * @sine_wave: sine wave to display
 */
void display_sine_osodial_wave_on_ncurses(float* sine_wave) {
	/* Initialize ncurses */
	initscr();
	cbreak();
	noecho();

	/* Print sinusoidal wave */
	for (int i = 0; i < 1000; i++)
	{
		printw("%f\n", sine_wave[i]);
	}

	refresh();
	getch();
	endwin();
}
