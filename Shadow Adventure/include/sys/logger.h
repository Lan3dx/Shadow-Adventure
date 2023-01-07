#pragma once
#include <string>

std::string getTime(std::string); // get hours, minuts, seconds
std::string getDate(); // get date

void clog(std::string type, std::string logMsg); // write in file