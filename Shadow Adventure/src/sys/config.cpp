#include <Windows.h>
#include <iostream>
#include <fstream>
#include <chrono>

#include "../../include/sys/iniparser.h" 
#include "../../include/sys/config.h"

// clearing the console screen
void clear()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // clear screen of console
}

// basic console settings
void screen_config()
{
	void* activeBuffer = GetStdHandle(STD_OUTPUT_HANDLE);  // get active buffer
	SMALL_RECT zeroWindow = { 0, 0, 0, 0 }; 
	COORD zBuffer = { 1, 1 }; 
	SetConsoleWindowInfo(activeBuffer, TRUE, &zeroWindow); 
	SetConsoleScreenBufferSize(activeBuffer, zBuffer); 

	COORD bufferSize = { 106, 54 }; // set buffer size
	SMALL_RECT windowSize = { 0, 0, 106 - 1, 54 - 1 };  // set window size
	SetConsoleScreenBufferSize(activeBuffer, bufferSize); 
	SetConsoleWindowInfo(activeBuffer, TRUE, &windowSize); 

	CONSOLE_CURSOR_INFO structCursorInfo; // Disabling the cursor 
	GetConsoleCursorInfo(activeBuffer, &structCursorInfo); 
	structCursorInfo.bVisible = FALSE; 
	SetConsoleCursorInfo(activeBuffer, &structCursorInfo); 
}

void file_config(std::string filename)
{
  std::ifstream file(filename);
  if (!file) 
  {
    std::ofstream newFile(filename);
    if (newFile) 
    {
      if (filename == "settings/settings.ini") 
      {
        std::map<std::string, std::map<std::string, std::string>> iniData = parseIniFile(filename);
        iniData["main"]["first_launched"] = "1";
        iniData["main"]["FPSms"] = "5";
        writeIniFile(iniData, filename);
      }
      return;
    }
    else {
      return;
    }
  }
  else {
    return;
  }
}