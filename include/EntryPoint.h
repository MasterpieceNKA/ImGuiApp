#pragma once

#include "App.h"
#include "Logger.h"

extern ImGuiApp::App* ImGuiApp::CreateApp(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace ImGuiApp {

	int Main(int argc, char** argv)
	{
		ImGuiApp::Logger::Init();

		while (g_ApplicationRunning)
		{
			ImGuiApp::App* app = ImGuiApp::CreateApp(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#if defined(IMGUIAPP_DIST) && defined(IMGUIAPP_PLATFORM_WINDOWS)

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

#endif // IMGUIAPP_DIST && IMGUIAPP_PLATFORM_WINDOWS