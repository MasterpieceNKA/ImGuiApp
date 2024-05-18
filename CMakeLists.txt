cmake_minimum_required(VERSION 2.8.12)

project(imgui_app)

add_subdirectory(dependencies)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(dependencies/glew-2.1.0/include)

add_executable(app src/main.cpp)
target_link_libraries(app PUBLIC glew glfw imgui imgui-glfw imgui-opengl3)