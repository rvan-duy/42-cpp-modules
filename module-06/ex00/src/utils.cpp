#include "scalar_conversions.hpp"

// Checks if input string overflows when converted to int
bool overflowsInt(const std::string& input_str, const int num) {
  if (num == INT_MIN || num == INT_MAX) {
    if (strcmp(input_str.c_str(), "-2147483648") == 0 || strcmp(input_str.c_str(), "2147483647") == 0) {
      return false;
    } else {
      return true;
    }
  }
  return false;
}
