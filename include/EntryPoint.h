/**
 * @file EntryPoint.h
 * @author n.a (n.a@mail.com)
 * @brief Defines the Entry point for the application responsible which is controls how the main function is run
 * @version 0.0.0
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "App.h"
#include "IGA_Logger.h"

/// @brief Function defenition for creating the App instance
/// @param argc main function argument count
/// @param argv main function argument vector
/// @return Pointer to the App application instance
extern ImGuiApp::App* ImGuiApp::CreateApp(int argc, char** argv);
/// @brief Flag indicating the running state of the App application instance
bool g_ApplicationRunning = true;

namespace ImGuiApp {
	/**
	 * @brief main function entry point
	 * 
	 * @param argc main function argument count
	 * @param argv main function argument vector
	 * @return int main function exit flag
	 */
	int Main(int argc, char** argv)
	{
		ImGuiApp::IGA_Logger::Init();

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
/**
 * @brief Release build for Windows OS. App instance runs without a console output (to do)
 * 
 * @param hInst 
 * @param hInstPrev 
 * @param cmdline 
 * @param cmdshow 
 * @return int 
 */
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return ImGuiApp::Main(__argc, __argv);
}

#else
/**
 * @brief Default main function definition. Usually runs with a console output depending on the operating system
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char** argv)
{
	return ImGuiApp::Main(argc, argv);
}

#endif // IMGUIAPP_DIST && IMGUIAPP_PLATFORM_WINDOWS