#include "globals.hpp"

ID3D11Device* g_pd3dDevice = NULL;
ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
IDXGISwapChain* g_pSwapChain = NULL;
ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

WNDCLASSEXW wc;
HWND hwnd;
ImGuiIO* io;

std::vector<PROCESSENTRY32> procList;

char filenameA[MAX_PATH] = "N/A";