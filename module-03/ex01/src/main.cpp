#include <cassert>
#include <cstdlib>

#include "ScavTrap.hpp"

static void checkClapTrap(ClapTrap &trap, std::string name, unsigned int hit_points, unsigned int energy_points,
                          unsigned int attack_damage) {
  assert(trap.getName() == name);
  assert(trap.getHitPoints() == hit_points);
  assert(trap.getEnergyPoints() == energy_points);
  assert(trap.getAttackDamage() == attack_damage);
}

int main(void) {
  {
    ScavTrap hero("ScavTrap");

    checkClapTrap(hero, "ScavTrap", 100, 50, 20);
  }
  return EXIT_SUCCESS;
}