#include <string>

bool isInfinite(const std::string &str) {
  if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("+inff") || !str.compare("-inff")) {
    return true;
  }
  return false;
}

bool isDouble(const std::string &str) {
  bool found_dot = false;

  // Iterate over constant string
  for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++) {
    // Skip first - or +
    if ((*it == '-' || *it == '+') && it == str.cbegin()) {
      continue;
    }

    // Check for dot
    if (*it == '.') {
      if (found_dot == true) {
        return false;
      }
      found_dot = true;
      continue;
    }

    // Check if str is a valid double
    if (it == str.cend() - 1 && found_dot == true) {
      // Check if double value is out of range
      try {
        std::stod(str);
      } catch (const std::exception &e) {
        return false;
      }
      return true;
    }

    // Check if the rest of the characters are digits
    if (std::isdigit(*it) == false) {
      return false;
    }
  }
  return false;
}

bool isFloat(const std::string &str) {
  bool found_dot = false;

  // Iterate over constant string
  for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++) {
    // Skip first - or +
    if ((*it == '-' || *it == '+') && it == str.cbegin()) {
      continue;
    }

    // Check for dot
    if (*it == '.') {
      if (found_dot == true) {
        return false;
      }
      found_dot = true;
      continue;
    }

    // Check if str is a valid float
    if (*it == 'f' && it == str.cend() - 1 && found_dot == true) {
      // Check if float value is out of range
      try {
        std::stof(str);
      } catch (const std::exception &e) {
        return false;
      }
      return true;
    }

    // Check if the rest of the characters are digits
    if (std::isdigit(*it) == false) {
      return false;
    }
  }
  return false;
}

bool isInt(const std::string &str) {
  // Check if string contains anything else but numbers
  for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++) {
    if (std::isdigit(*it) == false) {
      return false;
    }
  }
  return true;
}

bool isChar(const std::string &str) {
  if (str.size() == 0) {
    return false;
  }
  if (str.size() == 1 && std::isalpha(str[0])) {
    return true;
  }
  return false;
}
