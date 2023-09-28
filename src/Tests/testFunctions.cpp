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

#define LineWidth 80

void Header(std::string string)
{
    size_t width = (LineWidth - string.size()) / 2;
    std::cout << std::right << std::setfill('-') << std::setw(width) << " ";
    std::cout << string;
    if(string.size() % 2) ++width;
    std::cout << std::left << std::setfill('-') << std::setw(width) << " " << "\n";
}

void Header(const char* string)
{
    Header(std::string(string));
}

void Footer(char const* string)
{
    Header(string);
    std::cout << "\n";
}