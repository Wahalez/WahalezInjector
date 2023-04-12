#pragma once

#include "includes.hpp"

bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void createAppWindow();
bool initializeDirect3D();
void showWindow();
void setupImguiContext();
void setupPlatformRendererBackends();
void startNewFrame();
void render(const float* color);
void cleanup();

ImGuiWindowFlags getWindowFlags();
void setNextWindowSizeAndPos();
void app();

void processCombo();

void OpenFileDialog(TCHAR* filename, int size);

void popupMessageAndExit(char* message);