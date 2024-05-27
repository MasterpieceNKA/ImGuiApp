/**
 * @file Layer.h
 * @author n.a (n.a@MasterpieceTechVideos.com)
 * @brief Defines the template class for ImGui frames
 * @version 0.0.0
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <GL/glew.h> 
#include <GLFW/glfw3.h>

namespace ImGuiApp {
    /**
     * @brief Template class for ImGui frames. An ImGui frame is marked by
     * 
     * ImGui::Begin("ImGui_Frame_Name");
     * ...
     * ...
     * ImGui::End();
     * 
     */
    class Layer
    {
    public:
        /// @brief Destroy the Layer object 
        virtual ~Layer() = default;
        /**
         * @brief Called after object has been added to m_LayerStack 
         * of the App application instance
         *  
         */
        virtual void OnAttach() {}
        /**
         * @brief Called when the App application instance is shutting down
         * 
         */
        virtual void OnDetach() {}
        /**
         * @brief Called at the start of the render loop
         * 
         * @param ts Time in seconds between the last and current frames
         */
        virtual void OnUpdate(float ts) {}
        /**
         * @brief Called in the render loop within the ImGui::NewFrame(); and ImGui::End(); lines
         * to render ImGui frame items
         * 
         */
        virtual void OnUIRender() {}
        /**
         * @brief Called after rendering loop ImGui frame items i.e. after ImGui::Render(); line 
         * 
         */
        virtual void OnPostUIRender() {} 
    };

}