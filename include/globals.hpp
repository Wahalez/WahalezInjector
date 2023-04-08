#pragma once

#include "includes.hpp"

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
