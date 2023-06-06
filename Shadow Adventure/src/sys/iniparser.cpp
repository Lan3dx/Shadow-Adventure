#include "../../include/sys/iniparser.h"

// delete space
std::string trim(const std::string& str)
{
  size_t first = str.find_first_not_of(' ');
  if (std::string::npos == first)
  {
    return str;
  }
  size_t last = str.find_last_not_of(' ');
  return str.substr(first, (last - first + 1));
}

std::map<std::string, std::map<std::string, std::string>> parseIniFile(const std::string filename)
{
  std::map<std::string, std::map<std::string, std::string>> iniData;
  std::ifstream file(filename);

  if (!file)
  {
    return iniData;
  }

  std::string line;
  std::string currentSection;

  while (std::getline(file, line))
  {
    line = trim(line);

    if (line.empty() || line[0] == ';')
    {
      continue;
    }
    else if (line[0] == '[' && line[line.length() - 1] == ']')
    {
      currentSection = trim(line.substr(1, line.length() - 2));
    }
    else
    {
      size_t equalsPos = line.find('=');
      if (equalsPos != std::string::npos)
      {
        std::string key = trim(line.substr(0, equalsPos));
        std::string value = trim(line.substr(equalsPos + 1));
        iniData[currentSection][key] = value;
      }
    }
  }

  file.close();
  return iniData;
}

void writeIniFile(const std::map<std::string, std::map<std::string, std::string>>& iniData, const std::string filename)
{
  std::ofstream file(filename);

  if (!file)
  {
    return;
  }

  for (const auto& section : iniData)
  {
    file << "[" << section.first << "]" << std::endl;
    for (const auto& entry : section.second)
    {
      file << entry.first << " = " << entry.second << std::endl;
    }
    file << std::endl;
  }

  file.close();
}