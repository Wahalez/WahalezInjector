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

bool injectDLL() {
    PROCESSENTRY32 selectedProc = procList.at(selectedProcess);

    DWORD procID = selectedProc.th32ProcessID;

    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procID);

    if (hProc && hProc != INVALID_HANDLE_VALUE) {
        void* loc = VirtualAllocEx(hProc, 0, (_tcslen(filenameA) + 1) * sizeof(TCHAR), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        if (loc != 0) {
            WriteProcessMemory(hProc, loc, filenameA, (_tcslen(filenameA) + 1) * sizeof(TCHAR), nullptr);

            HANDLE hThread = CreateRemoteThread(hProc, NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(LoadLibrary), loc, NULL, NULL);
            std::cout << "help" << std::endl;
            if (hThread)
                CloseHandle(hThread);
            else {
                CloseHandle(hProc);
                return false;
            }
        }
        CloseHandle(hProc);
    }
    else
        return false;

    return true;
}