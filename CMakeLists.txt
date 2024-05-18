cmake_minimum_required(VERSION 3.16)

project(ImGuiApp LANGUAGES CXX) 

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/dependencies)

include_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/glew-2.1.0/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/glm-1.0.1-light)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)


file(GLOB ImGuiApp_SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")


add_library(ImGuiAppLibrary STATIC ${ImGuiApp_SOURCE})

target_link_libraries(ImGuiAppLibrary PUBLIC glm glew glfw imgui imgui-glfw imgui-opengl3)

target_include_directories(
    ImGuiAppLibrary PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/dependencies/glew-2.1.0/include
    ${CMAKE_CURRENT_LIST_DIR}/dependencies/glm-1.0.1-light
    ${CMAKE_CURRENT_BINARY_DIR}/include
) 