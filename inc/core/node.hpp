/**
 * @file node.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __NODE_HPP__
#define __NODE_HPP__

#include "../util/activations.hpp"
#include "../util/execptions.hpp"

#include <vector>
#include <memory>

/**
 * @brief Neural Node template class
 * 
 * @tparam InType Input variable type
 */
class Node
{
public:
//Constructors & Destructors
Node() = delete;
Node(std::vector<double>& inputVector, std::vector<double>& outputVector, std::vector<double>& weightVector, double bias, std::shared_ptr<ActivationFunction> function)
    : m_inputs(inputVector), m_outputs(outputVector), m_weights(weightVector), m_bias(bias), m_activationFunction(function)
{
    if(m_weights.size() != m_inputs.size()) throw MismatchError();
#if TEST_MODE
    std::cout   << "Creating Node with "
                << m_inputs.size() << " inputs, "
                << m_weights.size() << " weights, "
                << m_outputs.size() << " outputs, "
                << "using " << m_activationFunction->Name() << "\n";
#endif
}

//Methods
void Process()
{
    Aggregate();
    Stimulate();
}
void UpdateWeights(double factor)
{
    for(auto& weight : m_weights)
        weight *= factor;
}

private:
//Methods
void Aggregate()
{
    for(size_t index{}; index < m_inputs.size(); ++index) 
        m_aggregate += m_weights[index] * m_inputs[index];
    m_aggregate += m_bias;
}
void Stimulate()
{
    m_aggregate = m_activationFunction->Run(m_aggregate);
    for(auto& output : m_outputs)
    {
        output = m_aggregate;
    }
}

//Variables
double m_aggregate{};

//Synapses
double m_bias{};
std::vector<double>& m_inputs;
std::vector<double>& m_outputs;
std::vector<double>& m_weights;

//Activation Function
std::shared_ptr<ActivationFunction> m_activationFunction;
};

#endif