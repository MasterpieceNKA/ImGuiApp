cmake_minimum_required(VERSION 3.16)

project(
    pbPlots 
    DESCRIPTION
        "A plotting library available in many programming languages."
    LANGUAGES CXX
)

if(NOT DEFINED CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
endif() 

add_library(${PROJECT_NAME}   
    ${CMAKE_CURRENT_LIST_DIR}/pbPlots/Cpp/pbPlots.hpp 
    ${CMAKE_CURRENT_LIST_DIR}/pbPlots/Cpp/pbPlots.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/pbPlots/Cpp/supportLib.hpp 
    ${CMAKE_CURRENT_LIST_DIR}/pbPlots/Cpp/supportLib.cpp  
)
