#include "../inc/head.h"


int parseDataFile() 
{
	std::ifstream inputFile;
	inputFile.open("Ingest.json");
	Json::Value root;
	inputFile >> root;
	std::ofstream outputFile;
	outputFile.open("results/output.json");
	Json::Value outputArray;
	for (Json::Value::iterator itr = root.begin(); itr != root.end(); ++itr) 
	{
		int day = (*itr)["day"].asInt();
		int month = (*itr)["month"].asInt();
		int year = (*itr)["year"].asInt();
		int sunspots = (*itr)["num_sunspots"].asInt();
		int julianDay = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;
		Json::Value result;
		result["julian_day"] = julianDay;
		result["num_sunspots"] = sunspots;
		outputArray.append(result);
		if (outputArray.size() == 100)
		{
			outputFile << outputArray << std::endl;
			outputArray.clear();
		}
	}
	if (outputArray.size() > 0)
	{
		outputFile << outputArray << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
