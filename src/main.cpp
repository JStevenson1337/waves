#include "../include/head.h"
#include <wx/init.h>

#if wxVERSION_NUMBER < 2900
    #include <wx/string.h>
#else
    #include <wx/crt.h>
#endif

int main()
{
	parseDataFile();
	plotFourier();
	int startCurses();
	
	return 0;
}
