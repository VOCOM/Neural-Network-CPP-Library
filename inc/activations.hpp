/**
 * @file activations.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __ACTIVATIONS_HPP__
#define __ACTIVATIONS_HPP__

#include <math.h>
#define EULER_NUMBER_L 2.71828182845904523536

/**
 * @brief Activation function interface
 * @brief CANNOT be used as a concrete class
 */
class ActivationFunction
{
public:
virtual double Run(const double&) = 0;
};

/**
 * @brief Sigmoid function activator.
 * @brief Limits output to -1 >= x >= 1
 * 
 * @tparam N Scaler
 */
template <int N>
class SigmoidActivator : public ActivationFunction
{
public:
double Run(const double& input)
{
    return (1 / (1 + pow(EULER_NUMBER_L, -input/m_scale)));
}

private:
double m_scale{N};

};

#endif