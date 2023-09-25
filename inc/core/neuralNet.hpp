/**
 * @file manager.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include "node.hpp"
#include "layers.hpp"

#include <memory>
#include <thread>

class NeuralNet
{
public:
// Constructor
NeuralNet() = delete;
NeuralNet(std::vector<double>& inputVector, std::vector<double>& outputVector)
    : m_input(inputVector), m_output(outputVector)
{
    m_output.resize(1);
}

// Singleton Getter
static NeuralNet& Initialise(std::vector<double>& inputVector, std::vector<double>& outputVector)
{
    static NeuralNet neuralNet(inputVector, outputVector);
    return neuralNet;
}

// Configure Neural Net
void Configure(std::vector<double>& inputVector, size_t outputWidth)
{
    m_input = inputVector;
    m_output.resize(outputWidth);
}

// Forward Pass
void ForwardPass()
{
    for(size_t index{}; index < m_layerPool.size(); ++index)
        m_layerPool[index]->Process();
    m_output = m_layerPool.back()->OutputVector();
}

// Add Layer
void AddLayer(std::vector<std::vector<double>>& weightVector, std::vector<double>& bias, std::shared_ptr<ActivationFunction> activator, size_t outputWidth = 1)
{
    std::vector<double>& layerInput = m_input;
    if(m_layerPool.size()) layerInput = m_layerPool.back()->OutputVector();
    std::unique_ptr<Layer> newLayer = std::make_unique<Layer>(layerInput, weightVector, bias, activator, outputWidth);
    m_layerPool.push_back(std::move(newLayer));
}

// List network
void Info()
{
    std::cout   << "Inputs: " << m_input.size() << "\n"
                << "Layers: " << m_layerPool.size() << "\n"
                << "Outputs: "<< m_output.size() << "\n\n";
}

private:
std::vector<std::unique_ptr<Layer>> m_layerPool;
std::vector<double>& m_input;
std::vector<double>& m_output;
};

#endif