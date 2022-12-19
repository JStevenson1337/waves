#include "../include/header.h"


/* Function to get sine osodial wave from CSV data */
void get_sine_osodial_wave_from_csv(char* filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		return;
	}

	/* Read data from CSV file and store in an array */
	float sine_wave[1000];
	int i = 0;
	while (fscanf(fp, "%f", &sine_wave[i]) != EOF) {
		i++;
	}
	fclose(fp);
}

/* Function to create Fourier transform */
void create_fourier_transform(float* sine_wave) {
	/* Create array to store Fourier transform */
	float fourier_transform[1000];
	int n = 1000;
	for (int i = 0; i < n; i++) {
		fourier_transform[i] = 0;
		for (int j = 0; j < n; j++) {
			fourier_transform[i] += sine_wave[j] * cos(2 * M_PI * i * j / n);
		}
	}
}
