/**
 * @file execptions.hpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __EXECPTIONS_HPP__
#define __EXECPTIONS_HPP__

#include <exception>
#include <iostream>

class MismatchError : public std::exception
{
public:
const char* what() const throw() { return "Number of weights & inputs mismatch!!!\n"; }

};

#endif