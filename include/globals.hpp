#pragma once

#include "imgui.h"
#include "backends/imgui_impl_win32.h"
#include "backends/imgui_impl_dx11.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include <d3d11.h>

#define HEIGHT 300
#define WIDTH 600

static const wchar_t* appName = L"Wahalez Injector";

extern ID3D11Device* g_pd3dDevice;
extern ID3D11DeviceContext* g_pd3dDeviceContext;
extern IDXGISwapChain* g_pSwapChain;
extern ID3D11RenderTargetView* g_mainRenderTargetView;

extern WNDCLASSEXW wc;
extern HWND hwnd;
extern ImGuiIO* io;

extern std::vector<PROCESSENTRY32> procList;
