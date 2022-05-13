#include <cstdlib>

#include "Harl.hpp"

int main(int argc, char *argv[]) {
  Harl harl;

  if (harl.checkValidInput(argv[1], argc) == true) {
    harl.complain(argv[1]);
  }
  else
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  return EXIT_SUCCESS;
}