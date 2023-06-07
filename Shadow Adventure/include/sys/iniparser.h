#pragma once

#include "includes.h"

std::map<std::string, std::map<std::string, std::string>> parseIniFile(const std::string);
void writeIniFile(const std::map<std::string, std::map<std::string, std::string>>&, const std::string);