#include <ctime>
#include <fstream>

#include "../../include/sys/logger.h"

std::string getTime(std::string split) // get hours, min, sec
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	return std::to_string(newtime.tm_hour) + split + std::to_string(newtime.tm_min) + split + std::to_string(newtime.tm_sec);
}
std::string getDate() // get date
{
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	return std::to_string(1900 + newtime.tm_year) + "-" + std::to_string(1 + newtime.tm_mon) + "-" + std::to_string(newtime.tm_mday);
}

void clog(std::string type, std::string logMsg) // write in file
{
	
	std::string filePath = "logs/" + getDate() + ".txt";
	std::string now = getTime(":");
	std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);
	ofs << "[" << now << "] " << "[" << type << "]: " << logMsg << '\n';
	ofs.close();
}