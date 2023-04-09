#include "helper.hpp"

const char* WcharToChar(const wchar_t* str) {
    static char buf[1024];
    WideCharToMultiByte(CP_UTF8, 0, str, -1, buf, sizeof(buf), NULL, NULL);
    return buf;
}

void _debug_printProcesses(std::vector<PROCESSENTRY32> procList) {
    std::cout << procList.size() << std::endl;
    for (const auto& pe : procList)
        std::wcout << pe.szExeFile << std::endl;
}

const char* ConcatenateStrings(DWORD processID, const wchar_t* fileName) {
    static char buf[1024];
    std::ostringstream oss;
    oss << processID << " " << WcharToChar(fileName);
    strncpy(buf, oss.str().c_str(), sizeof(buf));
    buf[sizeof(buf) - 1] = '\0';
    return buf;
}