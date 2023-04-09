#include "injector.hpp"

std::vector<PROCESSENTRY32> getProcList() {

    std::vector<PROCESSENTRY32> procList;
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap != INVALID_HANDLE_VALUE) {
        pe32.dwSize = sizeof(PROCESSENTRY32);
        if (Process32First(hProcessSnap, &pe32)) {
            do {
                procList.push_back(pe32);
            } while (Process32Next(hProcessSnap, &pe32));

        }
    }

    return procList;
}

