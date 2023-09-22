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

#define x 5
#define y 10

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    double bias{10};
    std::vector<double> weights{1, 1};
    std::vector<int> inputs{x, y};
    std::vector<double> outputs{0};
    SigmoidActivator<100> triggerFunction;

    std::cout << "Sigmoid of " << x << " is " << triggerFunction.Run(x) << "\n";
    std::cout << "Sigmoid of " << y << " is " << triggerFunction.Run(y) << "\n";
    std::cout << "Sigmoid of " << x+y+bias << " is " << triggerFunction.Run(x+y+bias) << "\n";

    Node<int, double> SigmoidNode(inputs, outputs, weights, bias, &triggerFunction);
    SigmoidNode.Process();

    for(size_t index{}; index < outputs.size(); ++index)
    {
        std::cout << "Output " << index << " value " << outputs[index] << "\n";
    }
}