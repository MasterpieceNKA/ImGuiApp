/**
 * @file Logger.cpp
 * @author n.a (na@MasterpieceTechVideos.com)
 * @brief Implementation of the class for creating a logger class using spdlog
 * @version 0.0.0
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <IGA_Logger.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace ImGuiApp
{
    std::shared_ptr<spdlog::logger> IGA_Logger::m_CoreLogger;
    std::shared_ptr<spdlog::logger> IGA_Logger::m_ClientLogger;

    void IGA_Logger::Init()
    {
        m_CoreLogger = spdlog::stdout_color_mt("ImGui App");
        m_CoreLogger->set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] [%n] %v%$");
        m_CoreLogger->set_level(spdlog::level::trace);

        m_ClientLogger = spdlog::stdout_color_mt("Client App");
        m_ClientLogger->set_pattern("%^[%Y-%m-%d %H:%M:%S.%e] [%n] %v%$");
        m_ClientLogger->set_level(spdlog::level::trace);

        
        auto fileLogger = spdlog::basic_logger_mt("FileLogger", "logs.txt");
        fileLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%n] %v");
        fileLogger->set_level(spdlog::level::trace);

        m_CoreLogger->sinks().push_back(fileLogger->sinks().front());
        m_ClientLogger->sinks().push_back(fileLogger->sinks().front());        
    }
}