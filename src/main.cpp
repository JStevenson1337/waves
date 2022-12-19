#include "../include/header.h"

/*
 * Main - Entry point of the program
 * @argc: number of arguments
 * @argv: double pointer to an array of arguments
 */


/* Include header files */
#include "../include/header.h"

/* Main function */
int main(int argc, char** argv)
{
	/* Check if filename is provided */
	if (argc < 2)
	{
		argv[1] = "../SN_ms_hem_V2.0.csv";
	}
	else if (argc > 2)
	{
		printf("Too many arguments supplied.\n");
		return 0;
	}
	else
	{
		char *filename = argv[1];
	}
	

	/* Get sine osodial wave from CSV data */
	float* sine_wave = get_sine_osodial_wave_from_csv(filename);

	/* Create Fourier transform */
	float* fourier_transform = create_fourier_transform(sine_wave);

	/* Display sine osodial wave on ncurses */
	display_sine_osodial_wave_on_ncurses(sine_wave);

	/* Display Fourier transform on wxwidgets */
	display_fourier_transform_on_wxwidgets(fourier_transform);

	return 0;
}
