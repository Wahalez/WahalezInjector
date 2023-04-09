#pragma once

#include <Windows.h>
#include <string>
#include <vector>
#include <TlHelp32.h>

std::vector<PROCESSENTRY32> getProcList();
