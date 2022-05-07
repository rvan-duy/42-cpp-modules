#include <cstdlib>
#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"

void leaks() { system("leaks -q unnecessary_voilence"); }

int main(void) {
  atexit(leaks);

  {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }

  {
    Weapon club = Weapon("crude spiked club");

    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }

  return 0;
}
