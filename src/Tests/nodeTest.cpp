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

#define SigmoidScaler 100

void NodeTest()
{
    std::cout << "Running API Tests on Nodes\n\n";
    // Initial Values
    std::vector<double>     weights {1, 1, 1, 1, 1};
    std::vector<double>     inputs  {1, 2, 3, 4, 5};
    std::vector<double>     outputs {0, 1};
    std::shared_ptr<SigmoidActivator<SigmoidScaler>> triggerFunction = std::make_shared<SigmoidActivator<SigmoidScaler>>();
    Header("Input Values");
    {
        std::cout << "Weights:\n  ";
        for(size_t index{}; index < weights.size(); ++index)
            std::cout << " [" << weights[index] << "]";
        std::cout << "\nInputs:\n  ";
        for(size_t index{}; index < inputs.size(); ++index)
            std::cout << " [" << inputs[index] << "]";
        std::cout << "\nOutputs:\n  ";
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << " [" << outputs[index] << "]";
        std::cout << "\n\n";
    }

    // Sigmoid Activator Baseline
    Header("Sigmoid Activator Function Baseline");
    {
        double aggregate{};
        std::cout << "Sigmoid of";
        for(size_t index{}; index < inputs.size(); ++index)
        {
            std::cout << " [" << inputs[index] << "," << weights[index] << "]";
            aggregate += inputs[index] * weights[index];
        }
        std::cout << " with scaler of " << triggerFunction->Scaler() << " is " << triggerFunction->Run(aggregate+10) << "\n\n";
    }

    // Single Node Test
    Header("Single Node Sigmoid Activated Test");
    {
        Node SigmoidNode(inputs, outputs, weights, 10, triggerFunction);
        SigmoidNode.Process();
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << "Output " << index << " value " << outputs[index] << "\n\n";
    }

    /* TODO: Double Node Tests */

    /* TODO: n-Node Tests */

    Header("Single Node Weight Factoring Test");
    {
        Node SigmoidNode(inputs, outputs, weights, 10, triggerFunction);
        SigmoidNode.Process();
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << "Output " << index << " value " << outputs[index] << "\n\n";
        std::cout << "Factoring weights by 90%\n";
        SigmoidNode.UpdateWeights(0.9);
        SigmoidNode.Process();
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << "Output " << index << " value " << outputs[index] << "\n\n";
        std::cout << "Factoring weights by 110%\n";
        SigmoidNode.UpdateWeights(1.1);
        SigmoidNode.Process();
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << "Output " << index << " value " << outputs[index] << "\n\n";
    }

    /* TODO: Activator Switching Tests */

    // END
    Footer("Node API Test END");

}