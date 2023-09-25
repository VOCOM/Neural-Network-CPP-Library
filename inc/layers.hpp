/**
 * @file layers.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __LAYERS_HPP__
#define __LAYERS_HPP__

#include "node.hpp"

#include <memory>

template <typename InType>
class Layer
{
public:
// Constructors
Layer() = delete;
Layer(std::vector<InType>& inputs, std::vector<std::vector<double>>& weights, std::vector<double>& bias, std::vector<ActivationFunction*>& activators, size_t width = 0, size_t outputSize = 1)
    : m_inputs(inputs), m_weights(weights), m_bias(bias), m_activators(activators), m_width(width)
{
    m_outputs.resize(outputSize);
#if TEST_MODE
    std::cout   << "Creating Layer " << m_layerID << " with "
                << m_inputs.size() << " inputs, "
                << m_weights[0].size() << " weights each, "
                << m_outputs.size() << " outputs\n";
#endif
    for(size_t index{}; index < m_width; ++index)
    {
        std::unique_ptr<Node<InType>> newNode = std::make_unique<Node<InType>>(m_inputs, m_outputs, m_weights[index], m_bias[index], m_activators[index]);
        m_nodes.push_back(std::move(newNode));
    }
}

// Methods
void Process()
{
    for(auto& node : m_nodes)
    {
        node->Process();
    }
}
const std::vector<double>& GetOutput()
{
    return m_outputs;
}

private:
// Variables
size_t m_layerID{};

// Synapses
std::vector<InType>& m_inputs;
std::vector<std::vector<double>>& m_weights;
std::vector<double>& m_bias;
std::vector<ActivationFunction*>& m_activators;
std::vector<double> m_outputs;

// Nodes
std::vector<std::unique_ptr<Node<InType>>> m_nodes;
size_t m_width{};

};

#endif