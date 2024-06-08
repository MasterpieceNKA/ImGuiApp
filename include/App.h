/**
 * @file App.h
 * @author n.a (n.a@mail.com)
 * @brief This file defines the App class responsible for maintaining the lifecycle of the application
 * @version 0.0.0
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "Layer.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "imgui.h"

struct GLFWwindow;

namespace ImGuiApp {
    /**
     * @brief Struct for defining the default application window name and window size (width and height)
     * 
     */
    struct AppSpecification
    {
        /// @brief Default application name used by the App instance
        std::string Name = "ImGui App";
        /// @brief Default width of the main window for the application used by the App instance
        uint32_t Width = 1600;
        /// @brief Default width of the main window for the application used by the App instance
        uint32_t Height = 900;
    };
    /**
     * @brief Class for maintaining the life cycle of the application
     * 
     */
    class App
    {
        public:
            /**
             * @brief Construct a new App object using the default AppSpecification settings (name, window size)
             * 
             * @param appSpecification 
             */
            App(const AppSpecification& appSpecification = AppSpecification());

            /**
             * @brief Virtual destructor of the App object ensures the child class constructors are called before running
             * 
             */
            virtual ~App();

            /**
             * @brief Returns static instance of the App object
             * 
             * @return App& 
             */
            static App& Get();

            /**
             * @brief Maintains the applications render "while" loop
             * 
             */
            void Run();

            /**
             * @brief Enables addition of ImGui::MenuItem objects to the App application object
             * 
             * @param menubarCallback 
             */
            void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }

            /**
             * @brief Enables addition of ImGui frame items to the App application object 
             * 
             * @tparam T Instance of Layer object of the ImGui frame being added
             */
            template<typename T>
            void PushLayer()
            {
                static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
                m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
            }

            /**
             * @brief Enables addition of ImGui frame items to the App application object
             * 
             * @param layer Instance of Layer object of the ImGui frame being added 
             */
            void PushLayer(const std::shared_ptr<Layer>& layer) { m_LayerStack.emplace_back(layer); layer->OnAttach(); }

            /**
             * @brief Sets m_Running to true to enable shutting down the app.
             * 
             */
            void Close();
            /**
             * @brief Returns the time elapsed since the program started running (since GLFW was initialized)
             * 
             * @return float time in seconds
             */
            float GetTime();
            /**
             * @brief Get the main Window Handle object of the application
             * 
             * @return GLFWwindow* Pointer to the main Window of the application
             */
            GLFWwindow* GetWindowHandle() const { return m_WindowHandle; } 

        private:
            /**
             * @brief Initialises ImGui environment for the app eg creating the applications main window and initialising OpenGL
             * 
             */
            void Init();
            /**
             * @brief Performs cleanup while shutting down eg destroying windows and freeing up the OpenGL context
             * 
             */
            void Shutdown();
        private:
            /// @brief AppSpecification containing the name and window size of the App instance
            AppSpecification m_Specification;
            /// @brief  Pointer to the main window of the App intance
            GLFWwindow* m_WindowHandle = nullptr;
            /// @brief  Flag indicating the lifecycle state of the App application instance
            bool m_Running = false; 
            /// @brief Frame update time for the application. Inverse of the applications frame rate.
            float m_TimeStep = 0.0f;
            float m_FrameTime = 0.0f;
            float m_LastFrameTime = 0.0f;
            // Collection of menu callback functions
            std::function<void()> m_MenubarCallback;
        public:
            // Collection of Layer ImGui frames
            std::vector<std::shared_ptr<Layer>> m_LayerStack;
    };
    
    /**
     * @brief Create a App object. Implemented by CLIENT
     * 
     * @param argc main function argument count
     * @param argv main function argument vector
     * @return App* 
     */
    App* CreateApp(int argc, char** argv);
}
