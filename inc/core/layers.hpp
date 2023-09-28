/**
 * @file layers.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __LAYERS_HPP__
#define __LAYERS_HPP__

#include "node.hpp"

class Layer
{
public:
// Constructors
Layer() = delete;
Layer(std::vector<double>& inputs, std::vector<std::vector<double>>& weightVector, std::vector<double>& bias, std::shared_ptr<ActivationFunction>& activator, size_t outputWidth)
    : m_inputs(inputs), m_weights(weightVector), m_bias(bias), m_activator(activator)
{
    m_outputs.resize(outputWidth);
#if TEST_MODE
    std::cout   << "Creating Layer with "
                << m_inputs.size() << " inputs, "
                << m_weights.size() << " deep, "
                << m_weights[0].size() << " weights each, "
                << m_outputs.size() << " outputs\n";
#endif
    for(size_t index{}; index < weightVector.size(); ++index)
    {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(m_inputs, m_outputs, m_weights[index], m_bias[index], m_activator);
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
std::vector<double>& OutputVector()
{
    return m_outputs;
}
size_t Width()
{
    return m_nodes.size();
}
void Info()
{
    std::cout << "Nodes: " << m_nodes.size() << "\n    ";
    for(size_t index{}; index < m_nodes.size(); ++index)
        m_nodes[index]->Info();
        std::cout << "\n";
}

private:
// Synapses
std::vector<double>&                    m_inputs;
std::vector<std::vector<double>>&       m_weights;
std::vector<double>&                    m_bias;
std::shared_ptr<ActivationFunction>&    m_activator;
std::vector<double>                     m_outputs;

// Nodes
std::vector<std::unique_ptr<Node>>      m_nodes;

};

#endif