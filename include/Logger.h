/**
 * @file Logger.h
 * @author n.a (na@MasterpieceTechVideos.com)
 * @brief Defines the class for creating a logger class using spdlog
 * @version 0.0.0
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once 
#include <spdlog/spdlog.h>
#include <filesystem>

namespace ImGuiApp
{
    /**
     * @brief Class for performing logging function
     * 
     */
    class Logger
    {
    public:
        /// @brief Initialises the class logging variables
        static void Init();
        /// @brief Returns the logger object for the core ImGuiApp app
        /// @return static instance of spdlog object
        static std::shared_ptr<spdlog::logger> GetCoreLogger() { return m_CoreLogger; }
        /// @brief Returns the logger object for the client ImGuiApp app
        /// @return static instance of spdlog object
        static std::shared_ptr<spdlog::logger> GetClientLogger() { return m_ClientLogger; }
    private:
        /// @brief static instance of spdlog object for the core ImGuiApp app
        static std::shared_ptr<spdlog::logger> m_CoreLogger;
        /// @brief static instance of spdlog object for the client ImGuiApp app
        static std::shared_ptr<spdlog::logger> m_ClientLogger;
    };
}
/// @brief Info level logger for the core ImGuiApp app e.g. IGA_CORE_INFO("Core info message")
#define IGA_CORE_INFO(...) ::ImGuiApp::Logger::GetCoreLogger()->info(__VA_ARGS__)
/// @brief Warning level logger for the core ImGuiApp app e.g. IGA_CORE_WARN("Core warning message")
#define IGA_CORE_WARN(...) ::ImGuiApp::Logger::GetCoreLogger()->warn(__VA_ARGS__)
/// @brief Error level logger for the core ImGuiApp app e.g. IGA_CORE_WARN("Core error message")
#define IGA_CORE_ERROR(...) ::ImGuiApp::Logger::GetCoreLogger()->error(__VA_ARGS__)

/// @brief Info level logger for the client ImGuiApp app e.g. IGA_INFO("Client info message")
#define IGA_INFO(...) ::ImGuiApp::Logger::GetClientLogger()->info(__VA_ARGS__)
/// @brief Warning level logger for the client ImGuiApp app e.g. IGA_WARN("Client warning message")
#define IGA_WARN(...) ::ImGuiApp::Logger::GetClientLogger()->warn(__VA_ARGS__)
/// @brief Error level logger for the client ImGuiApp app e.g. IGA_ERROR("Client error message")
#define IGA_ERROR(...) ::ImGuiApp::Logger::GetClientLogger()->error(__VA_ARGS__)


#define IGA_STRINGIFY_MACRO(macro) #macro

#define IGA_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if (!(check)) { IGA##type##ERROR(msg, __VA_ARGS__); __debugbreak(); } }

#define IGA_INTERNAL_ASSERT_WITH_MSG(type, check, ...) IGA_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define IGA_INTERNAL_ASSERT_WITH_NO_MSG(type, check, ...) IGA_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", IGA_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define IGA_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define IGA_ASSERT_GET_MACRO(...) IGA_ASSERT_GET_MACRO_NAME(__VA_ARGS__, IGA_INTERNAL_ASSERT_WITH_MSG, IGA_INTERNAL_ASSERT_WITH_NO_MSG)

/// @brief Assert macro for the core ImGuiApp app e.g. IGA_CORE_ASSERT(boolean_evaluation)
#define IGA_CORE_ASSERT(...) IGA_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) 
/// @brief Assert macro for the client ImGuiApp app e.g. IGA_ASSERT(boolean_evaluation)
#define IGA_ASSERT(...) IGA_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__)