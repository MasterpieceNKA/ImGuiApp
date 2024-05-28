/**
 * @file Timer.h
 * @author n.a (na@mail.com)
 * @brief Defines the classes for calculating the time for frame rate evaluation
 * @version 0.0.0
 * @date 2024-05-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <iostream>
#include <string>
#include <chrono>

namespace ImGuiApp {
	/**
	 * @brief Class for calculating the time for frame rate evaluation
	 * 
	 */
	class Timer
	{
	public:
		/**
		 * @brief Construct a new Timer object
		 * 
		 */
		Timer()
		{
			Reset();
		}
		/**
		 * @brief Resets timer to current time stamp
		 * 
		 */
		void Reset()
		{
			m_Start = std::chrono::high_resolution_clock::now();
		}
		/**
		 * @brief Calculates the time in seconds from when m_Start was updated
		 * 
		 * @return float time in seconds
		 */
		float Elapsed()
		{
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
		}
		/**
		 * @brief Returns time elasped in milli seconds
		 * 
		 * @return float 
		 */
		float ElapsedMillis()
		{
			return Elapsed() * 1000.0f;
		}

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};
	/**
	 * @brief Scoped timer
	 * 
	 */
	class ScopedTimer
	{
	public:
		ScopedTimer(const std::string& name)
			: m_Name(name) {}
		~ScopedTimer()
		{
			float time = m_Timer.ElapsedMillis();
			std::cout << "[TIMER] " << m_Name << " - " << time << "ms\n";
		}
	private:
		std::string m_Name;
		Timer m_Timer;
	};



}
