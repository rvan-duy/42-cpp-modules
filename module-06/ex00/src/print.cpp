#include "scalar_conversions.hpp"

void printInfinite(const char sign) {
  std::cout << "char:   Impossible" << std::endl;
  std::cout << "int:    Impossible" << std::endl;
  std::cout << "float:  " << sign << "inff" << std::endl;
  std::cout << "double: " << sign << "inf" << std::endl;
}

void printDouble(const double num) {
  int num_int = static_cast<int>(num);

  // Printing char
  std::cout << "char:   ";
  if (num_int < CHAR_MIN || num_int > CHAR_MAX) {
    std::cout << "Impossible" << std::endl;
  } else if (std::isprint(num_int) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(num_int) << std::endl;
  }

  // Printing other types
  std::cout << "int:    " << num_int << std::endl;
  std::cout << std::setprecision(1) << std::fixed;
  std::cout << "float:  " << static_cast<float>(num) << "f" << std::endl;
  std::cout << "double  " << num << std::endl;
}

void printFloat(const float num) {
  int num_int = static_cast<int>(num);

  // Printing char
  std::cout << "char:   ";
  if (num_int < CHAR_MIN || num_int > CHAR_MAX) {
    std::cout << "Impossible" << std::endl;
  } else if (std::isprint(num_int) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(num_int) << std::endl;
  }

  // Printing other types
  std::cout << "int:    " << num_int << std::endl;
  std::cout << std::setprecision(1) << std::fixed;
  std::cout << "float:  " << num << "f" << std::endl;
  std::cout << "double  " << static_cast<double>(num) << std::endl;
}

void printInt(const int num, const std::string &input_str) {
  const bool is_overflow = overflowsInt(input_str, num);
  
  // Printing char
  std::cout << "char:   ";
  if (num < CHAR_MIN || num > CHAR_MAX) {
    std::cout << "Impossible" << std::endl;
  } else if (std::isprint(num) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(num) << std::endl;
  }

  // Printing int
  std::cout << "int:    ";
  if (is_overflow) {
    std::cout << "Overflows" << std::endl;
  } else {
    std::cout << num << std::endl;
  }

  // Printing float
  std::cout << std::setprecision(1) << std::fixed;
  if (is_overflow) {
    std::cout << "float:  Inaccurate" << std::endl;
  } else {
    std::cout << "float:  " << static_cast<float>(num) << "f" << std::endl;
  }

  // Printing double
  if (is_overflow) {
    std::cout << "double: Inaccurate" << std::endl;
  } else {
    std::cout << "double  " << static_cast<double>(num) << std::endl;
  }
}

void printChar(const char ch) {
  std::cout << std::setprecision(1) << std::fixed;
  std::cout << "char:   " << ch << std::endl;
  std::cout << "int:    " << static_cast<int>(ch) << std::endl;
  std::cout << "float:  " << static_cast<float>(ch) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(ch) << std::endl;
}
