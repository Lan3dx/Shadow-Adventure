#include <Windows.h>
#include <iostream>
#include <chrono>

#include "..\..\include\sys\config.h"

// clearing the console screen
void clear()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); // clear screen of console
}

// basic console settings
void std_config()
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