#include <cstdlib>
#include <iostream>
#include <string>

// Input: String representation of a c++ literal
// - char, int, float, doable

// steps:
// - detect the type of literal
// - convert from string to actual type
// - convert it explicitly to the 3 other types
// - display the result as shown

static bool isInt(const std::string &str) {
  // Check if string contains anything else but numbers
  for (std::size_t index = 0; index < str.size(); index++) {
    if (!std::isdigit(str[index])) return false;
  };

  // Check if integer value is out of range
  try {
    std::stoi(str);
  } catch (const std::out_of_range &oor) {
    return false;
  }

  return true;
};

static void printInt(int num) {
  std::cout << "char:   ";
  if (num < CHAR_MIN || num > CHAR_MAX)
    std::cout << "Impossible" << std::endl;
  else if (!std::isprint(num))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << static_cast<char>(num) << std::endl;
  std::cout << "int:    " << num << std::endl;
  std::cout << "float:  " << num << ".0f" << std::endl;
  std::cout << "double: " << num << ".0" << std::endl;
};

static bool isChar(const std::string &str) {
  if (str.size() == 0) return false;
  if (str.size() == 1 && std::isalpha(str[0])) return true;
  return false;
};

static void printChar(char ch) {
  std::cout << "char:   " << ch << std::endl;
  std::cout << "int:    " << static_cast<int>(ch) << std::endl;
  std::cout << "float:  " << static_cast<float>(ch) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(ch) << ".0" << std::endl;
};

int main(int argc, char **argv) {
  std::string input_string(argv[1]);

  if (argc == 2) {
    if (isChar(input_string) == true) {
      char casted_char = static_cast<char>(input_string[0]);
      printChar(casted_char);
      return EXIT_SUCCESS;
    };

    if (isInt(input_string) == true) {
      int casted_int = std::stoi(input_string);
      printInt(casted_int);
      return EXIT_SUCCESS;
    };
  };
  return EXIT_SUCCESS;
};
