#include "../include/header.h"

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

/*
 * display_fourier_transform_on_ncurses - displays a Fourier transform on wxwidgets
 * @fourier_transform: Fourier transform to display
 */
void display_fourier_transform_on_wxwidgets(float* fourier_transform)
{
	/* Initialize wxwidgets */
	wxApp* app = new wxApp();
	wxFrame* window = new wxFrame(nullptr, wxID_ANY, "Fourier Transform");

	/* Create panel and set size */
	wxPanel* panel = new wxPanel(window, wxID_ANY);
	panel->SetSize(1000, 1000);

	/* Draw Fourier transform on panel */
	wxClientDC dc(panel);
	dc.SetPen(wxPen(*wxBLACK, 4));
	for (int i = 0; i < 1000; i++) {
		int x = i;
		int y = fourier_transform[i];
		dc.DrawPoint(x, y);
	}

	window->Show(true);

	app->MainLoop();
}
