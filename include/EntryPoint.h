#pragma once

#include "App.h"

extern ImGuiApp::App* ImGuiApp::CreateApp(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace ImGuiApp {

	int Main(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			ImGuiApp::App* app = ImGuiApp::CreateApp(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#if defined(WL_DIST) && defined(WL_PLATFORM_WINDOWS)

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return ImGuiApp::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
	return ImGuiApp::Main(argc, argv);
}

#endif // WL_DIST && WL_PLATFORM_WINDOWS