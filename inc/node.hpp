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

#include "execptions.hpp"
#include "activations.hpp"

#include <vector>
#include <memory>

/**
 * @brief Neural Node template class
 * 
 * @tparam InType Input variable type
 * @tparam OutType Output variable type
 */
template <typename InType, typename OutType>
class Node
{
public:
//Constructors & Destructors
Node() = delete;
Node(std::vector<InType>& inputVector, std::vector<OutType>& outputVector, std::vector<double>& weightVector, double bias, ActivationFunction* function)
    : m_inputs(inputVector), m_outputs(outputVector), m_weights(weightVector), m_bias(bias), m_activationFunction(function)
{
#if TEST_MODE
    std::cout   << "Creating Node " << m_nodeID << " with "
                << m_inputs.size() << " inputs, "
                << m_weights.size() << " weights, "
                << m_outputs.size() << " outputs, "
                << "using " << m_activationFunction->Name() << "\n";
#endif
    if(m_weights.size() != m_inputs.size()) throw MismatchError();
}

//Methods
void Process()
{
    Aggregate();
    Stimulate();
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
size_t m_nodeID{};
double m_aggregate{};

//Synapses
double m_bias{};
std::vector<InType>& m_inputs;
std::vector<OutType>& m_outputs;
std::vector<double>& m_weights;

//Activation Function
ActivationFunction* m_activationFunction;
};

#endif