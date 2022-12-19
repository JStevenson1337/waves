#include "../include/header.h"

/* C */
/* Generate C code based on the sineosodial wave with CSV data from NASA sunspot data using ncurses, wxwidgets and fouier transforms */


/* Include header files */
#include "../include/header.h"

/* Main function */
int main(int argc, char** argv) {
	char *filename = argv[1];

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
