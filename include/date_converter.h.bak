#ifndef __DATE_CONVERTER_H__
#define __DATE_CONVERTER_H__

/*
 * DateConverter - Base class for converting dates to Julian Day Numbers 
 * @num_sunspots - Pointer to the number of sunspots in the data
 * @dateToJulian - Converts a date to a Julian Day Number
 * @computeJulianDay - Computes the Julian Day Number
 */
class DateConverter
{ 
public:
	float *num_sunspots()
	{
		if (num_sunspots <= 0)
		{
			return 0;
		}
		else
		{
			return num_sunspots;
		}
	}
	double dateToJulian(ss_data data)
	{
		while (data !<= 0)
		{
			ss_data.year << data[1];
			ss_data.month << data[2];
			ss_data.day << data[3];
		}
		return computeJulianDay(ss_data.year, ss_data.month, ss_data.day);
	}
private: 
	double computeJulianDay( _year,  _month, _day); 


	/*
	 * DateConverter::dateToJulian - Converts a date to a Julian Day Number
	 * @data - Sunspot data structure
	 * @return - Julian Day Number
	 */
	double DateConverter::dateToJulian(ss_data data)

	return computeJulianDay(ss_data.year, ss_data.month, ss_data.day); 


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

	/*
	 * parse_json - Parses the JSON file
	 * @filename - Name of the JSON file
	 * @return - Vector of plot_point structs
	 */
	int store_converted_data()
	{
		// create a vector of plot_point structs
		std::vector<t_data_p> data_points;
		data_points.push_back({1.0, 2.0});
		data_points.push_back({3.0, 4.0});
		data_points.push_back({5.0, 6.0});
	}
	// create a json array and populate it with data from the vector
	Json::Value json_data;
	for (auto &p : data_points) 
	{
		Json::Value point;
		point["x"] = p.x;
		point["y"] = p.y;
		json_data.append(point);
	}	

	// write the json data to a file
	std::ofstream out_file("../Store_Data.json");
	out_file << json_data.toStyledString() << std::endl;
	out_file.close();

	return 0;
};

#endif // __DATE_CONVERTER_H__
