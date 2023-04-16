#include "gui.hpp"

// #define _DEBUG_

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    procList = getProcList();

#ifdef _DEBUG_
    _debug_printProcesses(procList);
#endif

    createAppWindow();
    if (!initializeDirect3D())
        return 1;
    showWindow();
    setupImguiContext();
    ImGui::StyleColorsLight();
    setupPlatformRendererBackends();

    // Application state
    bool done = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!done)
    {
        MSG msg;
        while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        startNewFrame();
        app();

        const float clear_color_with_alpha[4] = {clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w};
        render(clear_color_with_alpha);
        g_pSwapChain->Present(1, 0);
    }

    cleanup();

    return 0;
}
