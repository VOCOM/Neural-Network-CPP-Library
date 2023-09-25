/**
 * @file testFunctions.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../inc/tests.hpp"

void Header(char const* string)
{
    std::cout << std::right << std::setfill('-') << std::setw(LineWidth) << " ";
    std::cout << string;
    std::cout << std::left << std::setfill('-') << std::setw(LineWidth) << " " << "\n";
}

void Footer(char const* string)
{
    Header(string);
    std::cout << "\n";
}