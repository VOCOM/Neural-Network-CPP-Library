/**
 * @file neuralNet.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include "node.hpp"
#include "layers.hpp"

#include <iostream>
#include <thread>

/**
 * @brief Single Instance Neural Net
 * 
 */
class NeuralNet
{
public:
// Singleton Getter
static NeuralNet& Initialise(std::vector<double>& inputVector, std::vector<double>& outputVector)
{
    static NeuralNet neuralNet(inputVector, outputVector);
    return neuralNet;
}

// Methods
void Configure(std::vector<double>& inputVector, size_t outputWidth)
{
    m_input = inputVector;
    m_output.resize(outputWidth);
}
void ForwardPass()
{
    for(size_t index{}; index < m_layerPool.size(); ++index)
        m_layerPool[index]->Process();
    m_output = m_layerPool.back()->OutputVector();
}
void BackwardPropagate()
{
    /* TODO */
    /* Weight Refactor each layer */
    /* Increase Epoch count */
}
void AddLayer(std::vector<std::vector<double>>& weightVector, std::vector<double>& bias, std::shared_ptr<ActivationFunction> activator, size_t outputWidth = 1)
{
    std::vector<double>& layerInput =
        m_layerPool.size() ? m_layerPool.back()->OutputVector() : m_input;
    std::unique_ptr<Layer> newLayer =
        std::make_unique<Layer>(layerInput, weightVector, bias, activator, outputWidth);
    m_layerPool.push_back(std::move(newLayer));
}
void RemoveLayer(size_t index)
{
    /* TODO */
    /* Will require layer pool migration to linked lists */
}

// Utilities
void Info()
{
    std::cout   << "Inputs:  " << m_input.size() << "\n"
                << "Layers:  " << m_layerPool.size() << "\n"
                << "Outputs: " << m_output.size() << "\n\n";

    std::cout   << "Input Layer:\n  ";
    for(auto input : m_input)
        std::cout << "[" << input << "] ";
    std::cout << "\n\n";
    for(size_t index{}; index < m_layerPool.size(); ++index)
    {
        std::cout << "Hidden Layer " << index << "\n  ";
        m_layerPool[index]->Info();
        std::cout << "\n";
    }
    std::cout << "\nOutput Layer:\n  ";
    for(auto output : m_output)
        std::cout << "[" << output << "] ";
    std::cout << "\n\n";
}
void Save()
{
    /* TODO */
    /* Save Layer structure */
    /* Save Weights */
}
void Load()
{
    /* TODO */
    /* Read save file */
    /* Load layers with weights */
}

private:
// Synapses
std::vector<std::unique_ptr<Layer>>     m_layerPool;
std::vector<double>&                    m_input;
std::vector<double>&                    m_output;

// Corrections
std::pair<size_t,size_t>                m_epoch;
/*
Error vectors
MAE mean absolute error
MSE mean squared error
RMSE root mean squared error
*/

// Constructor
NeuralNet() = delete;
NeuralNet(std::vector<double>& inputVector, std::vector<double>& outputVector)
    : m_input(inputVector), m_output(outputVector)
{
    m_output.resize(1);
}

};

#endif