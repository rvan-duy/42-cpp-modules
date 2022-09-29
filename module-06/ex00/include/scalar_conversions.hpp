#ifndef CPP_MODULE_06_SCALAR_CONVERSIONS_HPP
#define CPP_MODULE_06_SCALAR_CONVERSIONS_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>

// Print functions
void printInfinite(const char sign);
void printInt(const int num, const std::string &input_str);
void printChar(const char c);
void printFloat(const float num);
void printDouble(const double num);

// isType functions
bool isInfinite(const std::string &str);
bool isDouble(const std::string &str);
bool isFloat(const std::string &str);
bool isInt(const std::string &str);
bool isChar(const std::string &str);

// Utility functions
bool overflowsInt(const std::string &input_str, const int num);

#endif  // CPP_MODULE_06_SCALAR_CONVERSIONS_HPP
