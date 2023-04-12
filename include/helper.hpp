#pragma once

#include <cstdlib>
#include <cwchar>
#include <Windows.h>
#include <vector>
#include <TlHelp32.h>
#include <iostream>
#include <sstream>
#include <tchar.h>
#include "globals.hpp"

const char* WcharToChar(const wchar_t* wide_string);

void _debug_printProcesses(std::vector<PROCESSENTRY32> procList);

const char* ConcatenateStrings(DWORD processID, const wchar_t* exeFileName);

bool injectDLL();