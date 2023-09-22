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

#include <vector>
#include <memory>
#include <map>

template <typename InType, typename OutType>
class Node
{
public:
//Node Pool
static std::map<size_t, std::unique_ptr<Node>> NodePool;

//Constructors & Destructors
Node() = delete;
Node(std::vector<InType>& inputVector, std::vector<OutType>& outputVector, std::vector<double>& weightVector, double bias, double (*activationFunction)(const InType&))
    : m_inputs(inputVector), m_outputs(outputVector), m_weights(weightVector), m_bias(bias), m_activationFunction(activationFunction)
{
    if(m_weights.size() != m_inputs.size()) throw MismatchError();
    std::cout << "Node created with " << m_inputs.size() << " Inputs & " << m_weights.size() << " Weights\n";
}

//Methods
void Process()
{
    
}

private:
//Methods
void Aggregate();
void ActivationFunction();

//Variables
size_t m_nodeID;
double m_bias{};
std::vector<InType>& m_inputs;
std::vector<OutType>& m_outputs;
std::vector<double>& m_weights;
double (*m_activationFunction)(const InType&);
};

#endif