#include <ctype.h>

#include <cstdlib>
#include <iostream>

#include "iter.hpp"

void myToUpperPrint(const char& c) {
  if (std::isalpha(c)) {
    std::cout << (char)std::toupper(c);
  } else {
    std::cout << c;
  }
}

void myIncrementWithTenPrint(const int& i) {
  std::cout << i + 10 << " ";
}

void myIncrementWithTenPrint(const double& d) {
  std::cout << d + 10 << " ";
}

void myToUpperPrint(const std::string& s) {
  for (std::size_t i = 0; i < s.length(); i++) {
    std::cout << (char)std::toupper(s[i]);
  }
  std::cout << " ";
}

int main() {
  std::cout << "Testing char array" << std::endl;
  {
    char arr[] = "Hello world!";
    iter(arr, sizeof(arr) / sizeof(char), &myToUpperPrint);
    std::cout << std::endl;
  }

  std::cout << "Testing int array" << std::endl;
  {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, sizeof(arr) / sizeof(int), &myIncrementWithTenPrint);
    std::cout << std::endl;
  }

  std::cout << "Testing double array" << std::endl;
  {
    double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(arr, sizeof(arr) / sizeof(double), &myIncrementWithTenPrint);
    std::cout << std::endl;
  }

  std::cout << "Testing string array" << std::endl;
  {
    std::string arr[] = {"Hello", "world", "!"};
    iter(arr, sizeof(arr) / sizeof(std::string), &myToUpperPrint);
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}
