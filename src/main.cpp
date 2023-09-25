/**
 * @file main.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../inc/tests.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "RSE4207 Artificial Intelligence & Machine Learning Model\n\n";

    /* TODO: Cleaner Software */

    /* TODO: Activator Tests */
    //ActivatorTests();

    // Test Node API
    NodeTest();
    
    // Test Layer API
    LayerTests();
}