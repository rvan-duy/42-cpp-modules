#include <cstdlib>

#include "scalar_conversions.hpp"

int main(int argc, char **argv) {
  if (argc == 2) {
    std::string       input_string(argv[1]);
    std::stringstream ss;

    if (isChar(input_string) == true) {
      std::cout << "Scalar type: char" << std::endl;
      char casted_char = static_cast<char>(input_string[0]);
      printChar(casted_char);
      return EXIT_SUCCESS;
    }

    if (isInt(input_string) == true) {
      std::cout << "Scalar type: int" << std::endl;
      ss << input_string;
      int casted_int;
      ss >> casted_int;
      printInt(casted_int, input_string);
      return EXIT_SUCCESS;
    }

    if (isFloat(input_string) == true) {
      std::cout << "Scalar type: float" << std::endl;
      input_string.erase(input_string.find_last_of('f'), std::string::npos);
      ss << input_string;
      float casted_float;
      ss >> casted_float;
      printFloat(casted_float);
      return EXIT_SUCCESS;
    }

    if (isDouble(input_string) == true) {
      std::cout << "Scalar type: double" << std::endl;
      ss << input_string;
      double casted_double;
      ss >> casted_double;
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
  std::cout << "Usage: ./scalar_conversion [value]" << std::endl;

  return EXIT_SUCCESS;
}
