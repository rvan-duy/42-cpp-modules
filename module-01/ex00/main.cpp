#include <cstdlib>

#include "Zombie.hpp"

void    randomChump(std::string name);
Zombie *newZombie(std::string name);

// void leaks()
// {
// 	system("leaks -q zombie");
// }

void different_scope() {
  Zombie zombie("Stack");
  zombie.announce();
}

int main(void) {
  // atexit(leaks);
  Zombie *zombie = newZombie("Heap");
  zombie->announce();

  std::cout << "Entering a different scope" << std::endl;
  different_scope();
  std::cout << "Leaving a different scope" << std::endl;

  delete zombie;
  std::cout << "End of program." << std::endl;
  return EXIT_SUCCESS;
}
