
/* Function to display sine osodial wave on ncurses */
void display_sine_osodial_wave_on_ncurses(float* sine_wave) {
	/* Initialize ncurses */
	initscr();
	cbreak();
	noecho();

	/* Print sine osodial wave */
	for (int i = 0; i < 1000; i++) {
		printw("%f\n", sine_wave[i]);
	}

	/* Refresh screen */
	refresh();

	/* Wait for user input before exiting */
	getch();

	/* End ncurses */
	endwin();
}

/* Function to display Fourier transform on wxwidgets */
void display_fourier_transform_on_wxwidgets(float* fourier_transform) {
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

	/* Show window */
	window->Show(true);

	/* Start application */
	app->MainLoop();
}
