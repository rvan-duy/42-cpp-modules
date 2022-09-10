#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
  // Seed the random number generator
  std::srand(time(0));

  switch (std::rand() % 3) {
    case 0:
      return new A();
    case 1:
      return new B();
    default:
      return new C();
  }
};

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "Pointer (" << p << ") is an instance of class A" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "Pointer (" << p << ") is an instance of class B" << std::endl;
  } else if (dynamic_cast<C*>(p)) {
    std::cout << "Pointer (" << p << ") is an instance of class C" << std::endl;
  }
};

void identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    std::cout << "Pointer (" << &a << ") is an instance of class A" << std::endl;
  } catch (const std::bad_cast& e) {
    try {
      B& b = dynamic_cast<B&>(p);
      std::cout << "Pointer (" << &b << ") is an instance of class B" << std::endl;
    } catch (const std::bad_cast& e) {
      std::cout << "Pointer (" << &p << ") is an instance of class C" << std::endl;
      return;
    };
    return;
  };
  return;
};

int main() {
  Base* p = generate();
  std::cout << "Generated pointer: " << p << std::endl;
  identify(p);
  identify(*p);
  delete p;
  return EXIT_SUCCESS;
}