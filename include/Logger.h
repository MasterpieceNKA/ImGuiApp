#pragma once 
#include <spdlog/spdlog.h>
#include <filesystem>

namespace ImGuiApp
{
    class Logger
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger> GetCoreLogger() { return m_CoreLogger; }
        static std::shared_ptr<spdlog::logger> GetClientLogger() { return m_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> m_CoreLogger;
        static std::shared_ptr<spdlog::logger> m_ClientLogger;
    };
}

#define IGA_CORE_INFO(...) ::ImGuiApp::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define IGA_CORE_WARN(...) ::ImGuiApp::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define IGA_CORE_ERROR(...) ::ImGuiApp::Logger::GetCoreLogger()->error(__VA_ARGS__)

#define IGA_INFO(...) ::ImGuiApp::Logger::GetClientLogger()->info(__VA_ARGS__)
#define IGA_WARN(...) ::ImGuiApp::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define IGA_ERROR(...) ::ImGuiApp::Logger::GetClientLogger()->error(__VA_ARGS__)


#define IGA_STRINGIFY_MACRO(macro) #macro

#define IGA_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if (!(check)) { IGA##type##ERROR(msg, __VA_ARGS__); __debugbreak(); } }

#define IGA_INTERNAL_ASSERT_WITH_MSG(type, check, ...) IGA_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define IGA_INTERNAL_ASSERT_WITH_NO_MSG(type, check, ...) IGA_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", IGA_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define IGA_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define IGA_ASSERT_GET_MACRO(...) IGA_ASSERT_GET_MACRO_NAME(__VA_ARGS__, IGA_INTERNAL_ASSERT_WITH_MSG, IGA_INTERNAL_ASSERT_WITH_NO_MSG)

#define IGA_ASSERT(...) IGA_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__)
#define IGA_CORE_ASSERT(...) IGA_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__)