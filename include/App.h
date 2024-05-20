#pragma once
#include "Layer.h"

#include <string>
#include <vector>
#include <memory>
#include <functional>

#include "imgui.h"

struct GLFWwindow;

namespace ImGuiApp {
    struct AppSpecification
    {
        std::string Name = "ImGui App";
        uint32_t Width = 1600;
        uint32_t Height = 900;
    };
    class App
    {
        public:
            App(const AppSpecification& appSpecification = AppSpecification());
            virtual ~App();

            static App& Get();

            void Run();
            void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; }

            template<typename T>
            void PushLayer()
            {
                static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
                m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
            }

            void PushLayer(const std::shared_ptr<Layer>& layer) { m_LayerStack.emplace_back(layer); layer->OnAttach(); }

            void Close();

            float GetTime();
            GLFWwindow* GetWindowHandle() const { return m_WindowHandle; }
        private:
            void Init();
            void Shutdown();
        private:
            AppSpecification m_Specification;
            GLFWwindow* m_WindowHandle = nullptr;
            bool m_Running = false; 

            float m_TimeStep = 0.0f;
            float m_FrameTime = 0.0f;
            float m_LastFrameTime = 0.0f;

            std::vector<std::shared_ptr<Layer>> m_LayerStack;
            std::function<void()> m_MenubarCallback;
    };
    // Implemented by CLIENT
    App* CreateApp(int argc, char** argv);
}
