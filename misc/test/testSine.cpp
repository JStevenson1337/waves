#include <wx/wx.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;

class wxPlotWindow : public wxLogWindow
{
public:
	wxPlotWindow(wxWindow *parent, wxWindowID id, const wxString &title = wxT("Plot Window"), long style = wxDEFAULT_FRAME_STYLE, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, const wxString &name = wxFrameNameStr);
	~wxPlotWindow();
	void SetData(vector<double> data);
	void Draw();
private:
	std::vector<double> data;
};

wxPlotWindow::wxPlotWindow(wxWindow *parent, wxWindowID id, const wxString &title, long style, const wxPoint &pos, const wxSize &size, const wxString &name) : wxLogWindow(parent, id, title, style, pos, size, name)
{
	
}

int main()
{
	wxPlotWindow *plotWindow = new wxPlotWindow(NULL, wxID_ANY, wxT("Plot Window"));

	std::vector<double> dataPoints;
	for(int i = 0; i < 1000; i++) {
		double x = rand() % 1000; // some random x-value
		double y = sin(x); // calculate the sinewave data point
		dataPoints.push_back(y);
	}
	plotWindow->SetData(dataPoints);
	plotWindow->Draw();
	return 0;
}
