cmake_minimum_required(VERSION 3.16)

project(ImGuiApp LANGUAGES CXX)  
if(NOT DEFINED CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
endif()

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/dependencies) 

set(ImGuiApp_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB ImGuiApp_SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")


add_library(ImGuiApp STATIC ${ImGuiApp_SOURCE})

target_link_libraries(ImGuiApp PUBLIC spdlog glm glew glfw imgui imgui-glfw imgui-opengl3)

target_include_directories(
    ImGuiApp PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/dependencies/glew-2.1.0/include
    ${CMAKE_CURRENT_LIST_DIR}/dependencies/glm-1.0.1-light 
    ${CMAKE_CURRENT_LIST_DIR}/include
) 

# setup internal project compile definition
if(WIN32)
    target_compile_definitions(ImGuiApp PRIVATE IMGUIAPP_PLATFORM_WINDOWS)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    MESSAGE(STATUS "ImGuiApp set to Release with Debug Info")
    target_compile_definitions(ImGuiApp PRIVATE IMGUIAPP_RELEASE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    MESSAGE(STATUS "ImGuiApp set to Release")
    target_compile_definitions(ImGuiApp PRIVATE IMGUIAPP_DIST)
else() # Debug
	MESSAGE(STATUS "ImGuiApp set to Debug from CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
	target_compile_definitions(ImGuiApp PRIVATE IMGUIAPP_DEBUG)
endif()

if(WIN32)
    target_link_libraries(ImGuiApp PUBLIC dwmapi)
endif()

install(TARGETS ImGuiApp DESTINATION bin)