#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

// Input: String representation of a c++ literal
// - char, int, float, doable

// steps:
// - detect the type of literal
// - convert from string to actual type
// - convert it explicitly to the 3 other types
// - display the result as shown

static bool isInfinite(const std::string &str) {
  if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("+inff") || !str.compare("-inff")) return true;
  return false;
}

static void printInfinite(const char sign) {
  std::cout << "char:   Impossible" << std::endl;
  std::cout << "int:    Impossible" << std::endl;
  std::cout << "float:  " << sign << "inff" << std::endl;
  std::cout << "double: " << sign << "inf" << std::endl;
}

static bool isDouble(const std::string &str) {
  bool found_dot = false;

  // Iterate over constant string
  for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++) {
    // Skip first - or +
    if ((*it == '-' || *it == '+') && it == str.cbegin()) continue;

    // Check for dot
    if (*it == '.') {
      if (found_dot == true) return false;
      found_dot = true;
      continue;
    }

    // Check if str is a valid double
    if (it == str.cend() - 1 && found_dot == true) {
      // Check if double value is out of range
      try {
        std::stod(str);
      } catch (const std::out_of_range &oor) {
        return false;
      }
      return true;
    }

    // Check if the rest of the characters are digits
    if (std::isdigit(*it) == false) return false;
  }
  return false;
}

static void printDouble(const double num) {
  int num_int = static_cast<int>(num);

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "char:   ";
  if (num_int < CHAR_MIN || num_int > CHAR_MAX)
    std::cout << "Impossible" << std::endl;
  else if (std::isprint(num_int) == false)
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << static_cast<char>(num_int) << std::endl;
  std::cout << "int:    ";
  if (num < INT_MIN || num > INT_MAX)
    std::cout << "Overflows" << std::endl;
  else
    std::cout << num_int << std::endl;
  std::cout << "float:  " << static_cast<float>(num) << "f" << std::endl;
  std::cout << "double  " << num + 1 << std::endl;
}

static bool isFloat(const std::string &str) {
  bool found_dot = false;

  // Iterate over constant string
  for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++) {
    // Skip first - or +
    if ((*it == '-' || *it == '+') && it == str.cbegin()) continue;

    // Check for dot
    if (*it == '.') {
      if (found_dot == true) return false;
      found_dot = true;
      continue;
    }

    // Check if str is a valid float
    if (*it == 'f' && it == str.cend() - 1 && found_dot == true) {
      // Check if float value is out of range
      try {
        std::stof(str);
      } catch (const std::out_of_range &oor) {
        return false;
      }
      return true;
    }

    // Check if the rest of the characters are digits
    if (std::isdigit(*it) == false) return false;
  }
  return false;
}

static void printFloat(const float num) {
  int num_int = static_cast<int>(num);

  std::cout << "char:   ";
  if (num_int < CHAR_MIN || num_int > CHAR_MAX)
    std::cout << "Impossible" << std::endl;
  else if (std::isprint(num_int) == false)
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << static_cast<char>(num_int) << std::endl;
  std::cout << "int:    ";
  if (num < INT_MIN || num > INT_MAX)
    std::cout << "Overflows" << std::endl;
  else
    std::cout << num_int << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float:  " << num << "f" << std::endl;
  std::cout << "double  " << static_cast<double>(num) << std::endl;
}

static bool isInt(const std::string &str) {
  // Check if string contains anything else but numbers
  for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++) {
    if (std::isdigit(*it) == false) return false;
  }

  // Check if integer value is out of range
  try {
    std::stoi(str);
  } catch (const std::out_of_range &oor) {
    return false;
  }
  return true;
}

static void printInt(const int num) {
  std::cout << "char:   ";
  if (num < CHAR_MIN || num > CHAR_MAX)
    std::cout << "Impossible" << std::endl;
  else if (std::isprint(num) == false)
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << static_cast<char>(num) << std::endl;
  std::cout << "int:    " << num << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float:  " << static_cast<float>(num) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static bool isChar(const std::string &str) {
  if (str.size() == 0) return false;
  if (str.size() == 1 && std::isalpha(str[0])) return true;
  return false;
}

static void printChar(const char ch) {
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "char:   " << ch << std::endl;
  std::cout << "int:    " << static_cast<int>(ch) << std::endl;
  std::cout << "float:  " << static_cast<float>(ch) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(ch) << std::endl;
}

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
      int casted_int = stoi(input_string);
      printInt(casted_int);
      return EXIT_SUCCESS;
    }

    if (isFloat(input_string) == true) {
      std::cout << "Scalar type: float" << std::endl;
      float casted_float = stof(input_string);
      printFloat(casted_float);
      return EXIT_SUCCESS;
    }

    if (isDouble(input_string) == true) {
      std::cout << "Scalar type: double" << std::endl;
      double casted_double = stod(input_string);
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
