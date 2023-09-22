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

#include "../inc/node.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    double bias{10};
    std::vector<double> weights{1, 3, 5, 7, 9};
    std::vector<int> inputs{2, 4, 6, 8};
    std::vector<int> outputs;
    double (*triggerFunction)(const int&);

    Node<int, int> n1(inputs, outputs, weights, bias, triggerFunction);

}