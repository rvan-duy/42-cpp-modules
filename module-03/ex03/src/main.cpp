#include <cassert>
#include <cstdlib>

#include "DiamondTrap.hpp"

static void checkDiamondTrap(DiamondTrap &trap, std::string name, unsigned int hit_points, unsigned int energy_points,
                          unsigned int attack_damage) {
  assert(trap.ScavTrap::ClapTrap::getName() == name + "_clap_name");
  assert(trap.FragTrap::ClapTrap::getName() == name + "_clap_name");
  assert(trap.getName() == name);
  assert(trap.getName() == name);
  std::cout << trap.ScavTrap::ClapTrap::getHitPoints() << std::endl;
  assert(trap.ScavTrap::ClapTrap::getHitPoints() == hit_points);
  std::cout << trap.FragTrap::ClapTrap::getHitPoints() << std::endl;
  assert(trap.FragTrap::ClapTrap::getHitPoints() == hit_points);
  std::cout << trap.ScavTrap::ClapTrap::getEnergyPoints() << std::endl;
  assert(trap.ScavTrap::ClapTrap::getEnergyPoints() == energy_points);
  std::cout << trap.FragTrap::ClapTrap::getEnergyPoints() << std::endl;
  assert(trap.FragTrap::ClapTrap::getEnergyPoints() == energy_points);
  assert(trap.ScavTrap::ClapTrap::getAttackDamage() == attack_damage);
  assert(trap.FragTrap::ClapTrap::getAttackDamage() == attack_damage);
}

int main(void) {

  DiamondTrap hero("Hero");
  checkDiamondTrap(hero, "Hero", 100, 50, 30);

  return EXIT_SUCCESS;
}