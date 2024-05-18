
# Include Dear GLFGLEW into build. 
set(OpenGL_GL_PREFERENCE LEGACY) 
add_subdirectory(glew-2.1.0/build/cmake) 

# Include Dear GLFW into build.
set(GLFW_BUILD_EXAMPLES OFF)
add_subdirectory(glfw-3.4)

# Include Dear ImGui into build.
set(IMGUI_EXAMPLES OFF)
set(IMGUI_IMPL_SDL OFF)
set(IMGUI_IMPL_WIN32 OFF)
set(IMGUI_IMPL_GLUT OFF)
set(IMGUI_IMPL_DX9 OFF)
set(IMGUI_IMPL_DX10 OFF)
set(IMGUI_IMPL_DX11 OFF)
set(IMGUI_IMPL_DX12 OFF)
set(IMGUI_IMPL_VULKAN OFF)
set(IMGUI_IMPL_OPENGL2 OFF)
add_subdirectory(imgui-1.90.6-docking)