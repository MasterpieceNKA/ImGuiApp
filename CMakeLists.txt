cmake_minimum_required(VERSION 3.16)

project(ImGuiApp LANGUAGES CXX) 

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/dependencies) 

set(ImGuiApp_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB ImGuiApp_SOURCE "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")


add_library(ImGuiAppLib STATIC ${ImGuiApp_SOURCE})

target_link_libraries(ImGuiAppLib PUBLIC glm glew glfw imgui imgui-glfw imgui-opengl3)

target_include_directories(
    ImGuiAppLib PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/dependencies/glew-2.1.0/include
    ${CMAKE_CURRENT_LIST_DIR}/dependencies/glm-1.0.1-light 
    ${CMAKE_CURRENT_LIST_DIR}/include
) 

# setup internal project compile definition
if(WIN32)
    target_compile_definitions(ImGuiAppLib PRIVATE IMGUIAPP_PLATFORM_WINDOWS)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    target_compile_definitions(ImGuiAppLib PRIVATE IMGUIAPP_LIB_RELEASE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(ImGuiAppLib PRIVATE IMGUIAPP_LIB_DIST)
else() # Debug
	MESSAGE(STATUS "ImGuiAppLib set to Debug from CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
	target_compile_definitions(ImGuiAppLib PRIVATE IMGUIAPP_LIB_DEBUG)
endif()