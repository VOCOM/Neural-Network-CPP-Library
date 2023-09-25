/**
 * @file tests.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __TEST_HPP__
#define __TEST_HPP__
#define TEST_MODE true

#include <iostream>
#include <iomanip>

#include "core/node.hpp"
#include "core/layers.hpp"
#include "core/neuralNet.hpp"

#define LineWidth 20

// Formatting functions
void Header(char const*);
void Footer(char const*);

// Tests
void ActivatorTests();
void NodeTest();
void LayerTests();

// Neural Net Tests
void NNLayerTests();

#endif