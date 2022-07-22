#include <cstdlib>
#include <cstring>
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return EXIT_SUCCESS;
  }

  for (std::size_t i = 1; argv[i]; i++) {
    for (std::size_t j = 0; j < std::strlen(argv[i]); j++) {
      std::cout << (char)std::toupper(argv[i][j]);
    }
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
