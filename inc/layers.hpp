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

template <typename InType, typename OutType>
class Layer
{
public:
// Constructors
Layer() = delete;
Layer(std::vector<InType> inputs, std::vector<OutType> outputs, std::vector<std::vector<double>> weights, std::vector<double> bias, std::vector<ActivationFunction*> activators, size_t width = 0)
    : m_inputs(inputs), m_outputs(outputs), m_weights(weights), m_bias(bias), m_activators(activators), m_width(width)
{
    for(size_t index{1}; index < m_width; ++index)
    {
        /* TODO: Migrate to std::unique_ptr (Smart Pointers) */
        Node<InType, OutType> newNode(m_inputs, m_outputs, m_weights[index], m_bias[index], m_activators[index]);
        m_nodes.push_back(newNode);
    }
}

private:
std::vector<InType>& m_inputs;
std::vector<OutType>& m_outputs;
std::vector<std::vector<double>>& m_weights;
std::vector<double>& m_bias;
std::vector<ActivationFunction*>& m_activators;
std::vector<Node<InType, OutType>&> m_nodes;
size_t m_width{};

};

#endif