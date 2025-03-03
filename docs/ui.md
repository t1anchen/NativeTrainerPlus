# Notes on UI #

## imgui approach ##

TL;DR it's possible but EXTREMELY EXPENSIVE.

Though reshade can be running in GTA5 and reshade is using imgui, the
code and glue parts between reshade core and imgui are heavily
customized (see [reshade runtime
initialization](https://github.com/crosire/reshade/blob/v6.4.0/source/runtime.cpp#L178)). Additionally,
reshade is using minhook to simplify hook directx, which is the
additional work you have to deal with. ChatGPT has provided a
prototype example for this approach (not verified but it looks like
you have to spend a lot of time on this meesy piece of code)

```cpp
#include <d3d11.h>
#include <Windows.h>
#include "MinHook.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"

// Hook DirectX Present function
typedef HRESULT(__stdcall* Present)(IDXGISwapChain*, UINT, UINT);
Present oPresent;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
    static bool initialized = false;
    if (!initialized) {
        // Init ImGui here
        initialized = true;
    }

    // ImGui Frame
    ImGui_ImplDX11_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("GTA V ImGui Menu");
    ImGui::Text("Hello from ImGui in GTA V!");
    ImGui::End();

    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    return oPresent(pSwapChain, SyncInterval, Flags);
}

// Hooking function (use MinHook)
void HookDirectX() {
    // Get pointer to DX11 swap chain
    // Hook IDXGISwapChain::Present using MinHook
}

void ScriptMain() {
    HookDirectX();
    while (true) {
        // Prevent game freeze
        Sleep(10);
    }
}
```

Possibly the applicable scope of imgui might be in a well-formed and
system-open application rather than large bloated source-closed thing.

## Scaleform approach ##

ChatGPT told me the built-in UI in GTA5 is called *Scaleform UI*,
which I found it is also used in ScriptHookV SDK samples. Guessing
this approach might be the easier way rather than dealing with DirectX
messy loops and hooks.

```cpp
#include "script.h"
#include "keyboard.h"

void ShowScaleformMessage(const char* message) {
    int scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");

    if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(scaleform)) {
        GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(scaleform, "CLEAR_ALL");
        GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(scaleform, "SET_CLEAR_SPACE", 200);
        GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(scaleform, "SET_DATA_SLOT", 0, PAD::GET_CONTROL_INSTRUCTIONAL_BUTTON(2, 201, true), message);
        GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(scaleform, "DRAW_INSTRUCTIONAL_BUTTONS", -1);
    }

    while (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(scaleform)) {
        GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(scaleform, 255, 255, 255, 255, 0);
        WAIT(0);
    }

    GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&scaleform);
}

void ScriptMain() {
    while (true) {
        if (IsKeyJustUp(VK_F5)) {
            ShowScaleformMessage("Press F5 to show this UI!");
        }
        WAIT(0);
    }
}
```
