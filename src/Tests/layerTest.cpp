/**
 * @file layerTest.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../inc/tests.hpp"

#define SigmoidScaler 100

void LayerTests()
{
    std::cout << "Running API Tests on Layers\n\n";
    // Inital values
    std::vector<std::vector<double>>    weights{{1}};
    std::vector<double>                 inputs{10};
    std::vector<double>                 outputs{0};
    std::vector<double>                 bias{0};
    std::shared_ptr<SigmoidActivator<SigmoidScaler>> Sigmoid = std::make_shared<SigmoidActivator<SigmoidScaler>>();
    std::shared_ptr<ActivationFunction> Function = Sigmoid;

    Header("Input Values");
    {
        std::cout << "Weights:\n  ";
        for(size_t index{}; index < weights.size(); ++index)
        {
            std::cout << "[";
            for(size_t index2{}; index2 < weights[index].size(); ++index2)
                std::cout << weights[index][index2] << (index2 + 1 == weights[index].size() ? "" : ",");
            std::cout << "] ";
        }
        std::cout << "\nInputs:\n  ";
        for(size_t index{}; index < inputs.size(); ++index)
            std::cout << "[" << inputs[index] << "] ";
        std::cout << "\nOutputs:\n  ";
        for(size_t index{}; index < outputs.size(); ++index)
            std::cout << "[" << outputs[index] << "] ";
        std::cout << "\n\n";
    }

    // Single Sigmoid Activator Baseline
    Header("Single Sigmoid Activator Baseline");
    {
        double aggregate{inputs[0]*weights[0][0]+bias[0]};
        std::cout << "Sigmoid of " << aggregate << " with scaler of " << Sigmoid->Scaler() << " is " << Sigmoid->Run(aggregate) << "\n\n";
    }

    // Single Layer Single Node Test
    Header("Single Layer Single Node Test");
    {
        Layer SingleLayer(inputs, weights, bias, Function, (size_t)1);
        SingleLayer.Process();
        outputs = SingleLayer.OutputVector();
        std::cout << "Output is: " << outputs[0] << "\n\n";
    }

    /* TODO: Single Layer n-Node Test */

    /* TODO: n-Layer n-Node Test */

    // END
    Footer("Layer API Test END");
}