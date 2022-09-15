#include <cstdlib>

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat human("human", 1);

  std::cout << "TEST 1" << std::endl;

  try {
    std::cout << human << std::endl;
    human.incrementGrade(10);
    std::cout << human << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "TEST 2" << std::endl;

  try {
    std::cout << human << std::endl;
    human.decrementGrade(200);
    std::cout << human << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "TEST 3" << std::endl;

  try {
    std::cout << human << std::endl;
    human.decrementGrade(20);
    std::cout << human << std::endl;
    human.incrementGrade(10);
    std::cout << human << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
