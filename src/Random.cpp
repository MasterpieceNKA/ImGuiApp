/**
 * @file Random.cpp
 * @author n.a (na@MasterpieceTechVideos.com)
 * @brief Implementation for some definitions in Random.h
 * @version 0.0.0
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Random.h" 

namespace ImGuiApp {

	std::mt19937 Random::s_RandomEngine;
	std::uniform_int_distribution<std::mt19937::result_type> Random::s_Distribution;

}