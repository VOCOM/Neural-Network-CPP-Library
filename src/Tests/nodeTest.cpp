/**
 * @file nodeTest.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../inc/tests.hpp"

void NodeTest()
{
    std::cout << "Running API Tests on Nodes\n\n";
    // Initial Values
    std::vector<double>     weights{1, 1, 1, 1, 1};
    std::vector<int>        inputs{1, 2, 3, 4, 5};
    std::vector<double>     outputs{0, 1};
    SigmoidActivator<100>   triggerFunction;
    std::cout << std::right << std::setfill('-') << std::setw(LineWidth) << " ";
    std::cout << "Input Values";
    std::cout << std::left << std::setfill('-') << std::setw(LineWidth) << " " << "\n";
    std::cout << "Weights:";
    for(size_t index{}; index < weights.size(); ++index)
        std::cout << " [" << weights[index] << "]";
    std::cout << "\nInputs: ";
    for(size_t index{}; index < inputs.size(); ++index)
        std::cout << " [" << inputs[index] << "]";
    std::cout << "\nOutputs:";
    for(size_t index{}; index < outputs.size(); ++index)
        std::cout << " [" << outputs[index] << "]";
    std::cout << "\n\n";

    // Sigmoid Activator Baseline
    {
        double aggregate{};
        std::cout << std::right << std::setfill('-') << std::setw(LineWidth) << " ";
        std::cout << "Sigmoid Activator Function Baseline";
        std::cout << std::left << std::setfill('-') << std::setw(LineWidth) << " " << "\n";
        std::cout << "Sigmoid of";
        for(size_t index{}; index < inputs.size(); ++index)
        {
            std::cout << " [" << inputs[index] << "," << weights[index] << "]";
            aggregate += inputs[index] * weights[index];
        }
        std::cout << " is " << triggerFunction.Run(aggregate+10) << "\n\n";
    }

    // Single Node Test
    {
        std::cout << std::right << std::setfill('-') << std::setw(LineWidth) << " ";
        std::cout << "Single Node Sigmoid Activated Test";
        std::cout << std::left << std::setfill('-') << std::setw(LineWidth) << " " << "\n";
        Node<int, double> SigmoidNode(inputs, outputs, weights, 10, &triggerFunction);
        SigmoidNode.Process();
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << "Output " << index << " value " << outputs[index] << "\n\n";
    }

    /* TODO: Double Node Tests */

    /* TODO: n-Node Tests */

    /* TODO: Activator Switching Tests */

    // END
    {
        std::cout << std::right << std::setfill('-') << std::setw(LineWidth) << " ";
        std::cout << "Node API Test END";
        std::cout << std::left << std::setfill('-') << std::setw(LineWidth) << " " << "\n\n";
    }

}