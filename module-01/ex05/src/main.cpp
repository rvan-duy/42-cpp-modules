#include <cstdlib>

#include "Harl.hpp"

int main(void) {
  Harl        harl;
  std::string test_strings[5] = {("DEBUG"), ("INFO"), ("WARNING"), ("ERROR"), ("RANDOM STRING")};

  harl.complain(test_strings[0]);
  harl.complain(test_strings[1]);
  harl.complain(test_strings[2]);
  harl.complain(test_strings[3]);
  harl.complain(test_strings[4]);
  return EXIT_SUCCESS;
}