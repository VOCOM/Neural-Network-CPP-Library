/**
 * @file nnTests.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../inc/tests.hpp"

void NNLayerTests()
{
    std::cout << "Running API Tests on Neural Net Layer Manager\n\n";
    // Initial Values
    std::vector<std::vector<double>>    weights {{1}};
    std::vector<double>                 inputs  {15};
    std::vector<double>                 outputs {1};
    std::vector<double>                 bias    {10};
    std::shared_ptr<SigmoidActivator<100>> triggerFunction = std::make_shared<SigmoidActivator<100>>();
    NeuralNet& neuralNet = NeuralNet::Initialise(inputs, outputs);
    Header("Input Values");
    {
        std::cout << "Weights:\n";
        for(size_t index{}; index < weights.size(); ++index)
        {
            std::cout << " {";
            for(size_t index2{}; index2 < weights[0].size(); ++index2)
                std::cout << " [" << weights[index][index2] << "]";
            std::cout << " }\n";
        }
        std::cout << "Inputs:\n";
        for(size_t index{}; index < inputs.size(); ++index)
            std::cout << " [" << inputs[index] << "]";
        std::cout << "\nOutputs:\n";
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << " [" << outputs[index] << "]";
        std::cout << "\n\n";
    }

    Header("Sigmoid Activator Function Baseline");
    {
        double aggregate{inputs[0] * weights[0][0]};
        std::cout << "Sigmoid of " << aggregate << " with scaler of " << triggerFunction->Scaler() << " is " << triggerFunction->Run(aggregate + bias[0]) << "\n\n";
        aggregate = triggerFunction->Run(aggregate + bias[0]);
        std::cout << "Sigmoid of " << aggregate << " with scaler of " << triggerFunction->Scaler() << " is " << triggerFunction->Run(aggregate + bias[0]) << "\n\n";
    }

    Header("Single Layer Test");
    {
        neuralNet.AddLayer(weights, bias, triggerFunction);
        neuralNet.ForwardPass();
        std::cout << "Outputs:\n";
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << " [" << outputs[index] << "]";
        std::cout << "\n\n";
    }

    Header("Double Layer Test");
    {
        neuralNet.AddLayer(weights, bias, triggerFunction);
        neuralNet.Info();
        neuralNet.ForwardPass();
        std::cout << "Outputs:\n";
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << " [" << outputs[index] << "]";
        std::cout << "\n\n";
    }

}
