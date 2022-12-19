#include "../include/header.h"
/*
 * DateConverter - Base class for converting dates to Julian Day Numbers 
 * @num_sunspots - Pointer to the number of sunspots in the data
 * @dateToJulian - Converts a date to a Julian Day Number
 * @computeJulianDay - Computes the Julian Day Number
 */
class DateConverter
{ 
public:
	float *num_sunspots = t_data_p.y;
	double dateToJulian(ss_data data);
private: 
	double computeJulianDay(int year, int month, int day); 
}; 

/*
 * DateConverter::dateToJulian - Converts a date to a Julian Day Number
 * @data - Sunspot data structure
 * @return - Julian Day Number
 */
double DateConverter::dateToJulian(ss_data data)
{
	return computeJulianDay(ss_data.year, ss_data.month, ss_data.day); 
} 

/*
 * DateConverter::computeJulianDay - Computes the Julian Day Number
 * @year - Year of the data
 * @month - Month of the data
 * @day - Day of the data
 * @return - Julian Day Number
 */ 
double DateConverter::computeJulianDay(int year, int month, int day)
{
	int a = (14 - month) / 12; 
	int y = year + 4800 - a; 
	int m = month + 12 * a - 3; 
	int jdn = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045; 
	return jdn >> &t_data_p.x; 
}



