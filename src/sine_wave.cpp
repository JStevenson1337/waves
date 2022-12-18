#include "../include/header.h"
#include "../include/matplotlibcpp.h"
namespace plt = matplotlibcpp;

int readCSV()
{
	std::string file = "SN_ms_hem_V2.0.csv";
	std::ifstream infile(file);
	std::string line;
	std::vector<std::string> row;
	std::vector<std::vector<std::string>> data;
	while (std::getline(infile, line))
	{
		std::stringstream ss(line);
		std::string cell;
		while (std::getline(ss, cell, ','))
		{
			row.push_back(cell);
		}
		data.push_back(row);
		
		row.clear();
	}
	return 0;
}






