#include <cstdlib>
#include <iostream>

#include "Array.hpp"

int main() {
  std::cout << "Testing with integers" << std::endl;
  {
    std::cout << "Testing constructor with size" << std::endl;
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++) {
      arr[i] = i;
    }
    for (unsigned int i = 0; i < arr.size(); i++) {
      std::cout << arr[i] << std::endl;
    }

    std::cout << "Testing copy constructor" << std::endl;
    Array<int> arr2(arr);
    for (unsigned int i = 0; i < arr2.size(); i++) {
      std::cout << arr2[i] << std::endl;
    }

    std::cout << "Testing operator[] that goes out of bound" << std::endl;
    {
      try {
        arr[5] = 0;
      } catch (std::exception& e) {
        std::cout << "Exception caught" << std::endl;
      }
    }
  }

  std::cout << "Testing with strings" << std::endl;
  {
    std::cout << "Testing constructor with size" << std::endl;
    Array<std::string> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++) {
      arr[i] = "Hello";
    }
    for (unsigned int i = 0; i < arr.size(); i++) {
      std::cout << arr[i] << std::endl;
    }

    std::cout << "Testing copy constructor" << std::endl;
    Array<std::string> arr2(arr);
    for (unsigned int i = 0; i < arr2.size(); i++) {
      std::cout << arr2[i] << std::endl;
    }

    std::cout << "Testing operator[] that goes out of bound" << std::endl;
    {
      try {
        arr[5] = "Hello";
      } catch (std::exception& e) {
        std::cout << "Exception caught" << std::endl;
      }
    }
  }

  return EXIT_SUCCESS;
}
