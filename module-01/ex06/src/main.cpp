#include <cstdlib>

#include "Harl.hpp"

int main(int argc, char *argv[]) {
  Harl harl;

  if (argc > 1)
    harl.complain(argv[1]);
  else
    std::cout << "How can we complain without a level?" << std::endl;
  return EXIT_SUCCESS;
}