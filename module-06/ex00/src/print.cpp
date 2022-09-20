#include <iomanip>
#include <iostream>

void printInfinite(const char sign) {
  std::cout << "char:   Impossible" << std::endl;
  std::cout << "int:    Impossible" << std::endl;
  std::cout << "float:  " << sign << "inff" << std::endl;
  std::cout << "double: " << sign << "inf" << std::endl;
}

void printDouble(const double num) {
  int num_int = static_cast<int>(num);

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "char:   ";
  if (num_int < CHAR_MIN || num_int > CHAR_MAX) {
    std::cout << "Impossible" << std::endl;
  } else if (std::isprint(num_int) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(num_int) << std::endl;
  }
  std::cout << "int:    ";
  if (num < INT_MIN || num > INT_MAX) {
    std::cout << "Overflows" << std::endl;
  } else {
    std::cout << num_int << std::endl;
  }
  std::cout << "float:  " << static_cast<float>(num) << "f" << std::endl;
  std::cout << "double  " << num << std::endl;
}

void printFloat(const float num) {
  int num_int = static_cast<int>(num);

  std::cout << "char:   ";
  if (num_int < CHAR_MIN || num_int > CHAR_MAX) {
    std::cout << "Impossible" << std::endl;
  } else if (std::isprint(num_int) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(num_int) << std::endl;
  }
  std::cout << "int:    ";
  if (num < INT_MIN || num > INT_MAX) {
    std::cout << "Overflows" << std::endl;
  } else {
    std::cout << num_int << std::endl;
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float:  " << num << "f" << std::endl;
  std::cout << "double  " << static_cast<double>(num) << std::endl;
}

void printInt(const std::string &input_str) {
  // Printing char
  int num;
  try {
    num = std::stoi(input_str);
  } catch (std::out_of_range &e) {
    num = INT_MAX;
  }
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
  try {
    int num_int = std::stoi(input_str);
    std::cout << num_int << std::endl;
  } catch (const std::out_of_range &e) {
    std::cout << "Overflows" << std::endl;
  }

  // Printing float
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float:  ";
  try {
    std::cout << std::stof(input_str) << "f" << std::endl;
  } catch (const std::out_of_range &e) {
    std::cout << "Overflows" << std::endl;
  }

  // Printing double
  std::cout << "double  ";
  try {
    std::cout << std::stod(input_str) << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Overflows" << std::endl;
  }
}

void printChar(const char ch) {
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "char:   " << ch << std::endl;
  std::cout << "int:    " << static_cast<int>(ch) << std::endl;
  std::cout << "float:  " << static_cast<float>(ch) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(ch) << std::endl;
}
