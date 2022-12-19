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
	free(app);
}



/*
 * Create Fourier Transform
 * @arr: array of data
 */
float* create_fourier_transform(float* arr)
{
	/* Get the length of the array */
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Create fourier transform array */
	float* fourier_transform = new float[n];

	/* Initialize fourier transform array */
	for (int i = 0; i < n; i++)
	{
		fourier_transform[i] = 0.0;
	}

	/* Perform fourier transform */
	for (int k = 0; k < n; k++)
	{
		for (int t = 0; t < n; t++)
		{
			fourier_transform[k] += arr[t] * cos(2 * PI * k * t / n);
		}
	}

	/* Return fourier_transform array */
	return fourier_transform;
}

/*
 * Display sine osodial wave on ncurses
 * @arr: array of data
 */
void display_sine_osodial_wave_on_ncurses(float* arr)
{
	/* Get the length of the array */
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Initialize ncurses */
	initscr();

	/* Get max size of window */
	int max_x = 0, max_y = 0;
	getmaxyx(stdscr, max_y, max_x);

	/* Get center coordinates of window */
	int center_x = max_x / 2;
	int center_y = max_y / 2;

	/* Draw sine osodial wave */
	for (int i = 0; i < n; i++)
	{
		mvprintw(center_y + arr[i], center_x + i, "*");
	}

	/* Refresh window */
	refresh();

	/* Wait for user input */
	getch();

	/* End ncurses */
	endwin();
}

/*
 * Display Fourier transform on wxwidgets
 * @arr: array of data
 */
void display_fourier_transform_on_wxwidgets(float* arr)
{
	/* Get the length of the array */
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Create wxwidgets application */
	wxApp* app = new wxApp();

	/* Create wxwidgets frame */
	wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Fourier Transform");

	/* Create wxwidgets panel */
	wxPanel* panel = new wxPanel(frame, wxID_ANY);

	/* Create wxwidgets sizer */
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	/* Add panel to sizer */
	sizer->Add(panel, 1, wxEXPAND);

	/* Set sizer for frame */
	frame->SetSizer(sizer);

	/* Set frame size */
	frame->SetSize(800, 600);

	/* Draw fourier transform on panel */
	for (int i = 0; i < n; i++)
	{
		wxPoint point(i, arr[i]);
		panel->DrawCircle(point, 5);
	}

	/* Show frame */
	frame->Show();

	/* Run wxwidgets application */
	app->MainLoop();
}
