#include <cstdlib>
#include <iostream>
#include <string>

// Why use references over pointers?
// - it can't be reassigned to another object
// - it can't be NULL

int main(void) {
  std::string  brain     = "HI THIS IS BRAIN";
  std::string *stringPTR = &brain;
  std::string &stringREF = brain;

  std::cout << "The memory address of the string brain variable is: " << &brain << std::endl;
  std::cout << "The memory address of the stringPTR is:             " << stringPTR << std::endl;
  std::cout << "The memory address of the stringREF is:             " << &stringREF << std::endl;

  std::cout << "The value of the string brain variable is:          " << brain << std::endl;
  std::cout << "The value pointed to by stringPTR is:               " << *stringPTR << std::endl;
  std::cout << "The value pointed to by stringREF is:               " << stringREF << std::endl;

  return EXIT_SUCCESS;
}
