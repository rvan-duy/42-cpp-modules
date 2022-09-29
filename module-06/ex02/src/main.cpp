#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
  switch (rand() % 3) {
    case 0:
      return new A();
    case 1:
      return new B();
    default:
      return new C();
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "Pointer     (" << p << ") is an instance of class A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "Pointer     (" << p << ") is an instance of class B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "Pointer     (" << p << ") is an instance of class C" << std::endl;
  }
}

void identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    std::cout << "Reference   (" << &a << ") is an instance of class A" << std::endl;
  } catch (std::exception& e) {
    try {
      B& b = dynamic_cast<B&>(p);
      std::cout << "Reference   (" << &b << ") is an instance of class B" << std::endl;
    } catch (std::exception& e) {
      std::cout << "Reference   (" << &p << ") is an instance of class C" << std::endl;
      return;
    }
    return;
  }
  return;
}

int main() {
  srand(time(NULL)); // use current time as seed for random generator
  
  // Generate an array of 10 random pointers to Base
  Base* array[10];
  for (int i = 0; i < 10; i++) {
    array[i] = generate();
  }

  // Identify each pointer in the array with both functions
  for (int i = 0; i < 10; i++) {
    std::cout << "Iteration " << i << ":" << std::endl;
    std::cout << "Generated   (" << array[i] << ")" << std::endl;
    identify(array[i]);
    identify(*array[i]);
  }

  // Delete each pointer in the array
  for (int i = 0; i < 10; i++) {
    delete array[i];
  }

  return EXIT_SUCCESS;
}
