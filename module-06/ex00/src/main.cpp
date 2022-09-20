#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

void printInfinite(const char sign);
void printInt(const std::string &input_str);
void printChar(const char c);
void printFloat(const float num);
void printDouble(const double num);

bool isInfinite(const std::string &str);
bool isDouble(const std::string &str);
bool isFloat(const std::string &str);
bool isInt(const std::string &str);
bool isChar(const std::string &str);

int main(int argc, char **argv) {
  if (argc == 2) {
    std::string input_string(argv[1]);

    if (isChar(input_string) == true) {
      std::cout << "Scalar type: char" << std::endl;
      char casted_char = static_cast<char>(input_string[0]);
      printChar(casted_char);
      return EXIT_SUCCESS;
    }

    if (isInt(input_string) == true) {
      std::cout << "Scalar type: int" << std::endl;
      printInt(input_string);
      return EXIT_SUCCESS;
    }

    if (isFloat(input_string) == true) {
      std::cout << "Scalar type: float" << std::endl;
      float casted_float = std::stof(input_string);
      printFloat(casted_float);
      return EXIT_SUCCESS;
    }

    if (isDouble(input_string) == true) {
      std::cout << "Scalar type: double" << std::endl;
      double casted_double = std::stod(input_string);
      printDouble(casted_double);
      return EXIT_SUCCESS;
    }

    if (isInfinite(input_string) == true) {
      char sign = input_string[0];
      printInfinite(sign);
      return EXIT_SUCCESS;
    }

    std::cout << "char:   Impossible" << std::endl;
    std::cout << "int:    Impossible" << std::endl;
    std::cout << "float:  nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  }
  return EXIT_SUCCESS;
}
