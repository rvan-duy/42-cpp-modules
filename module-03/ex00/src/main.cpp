#include <cassert>
#include <cstdlib>

#include "ClapTrap.hpp"

static void checkClapTrap(ClapTrap &trap, std::string name, unsigned int hit_points, unsigned int energy_points,
                          unsigned int attack_damage) {
  assert(trap.getName() == name);
  assert(trap.getHitPoints() == hit_points);
  assert(trap.getEnergyPoints() == energy_points);
  assert(trap.getAttackDamage() == attack_damage);
}

int main(void) {
  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ClapTrap Class with 10 attacks" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ClapTrap HeroClapTrap("HeroClapTrap");
    checkClapTrap(HeroClapTrap, "HeroClapTrap", 10, 10, 0);
    ClapTrap Bandit("Bandit");
    checkClapTrap(Bandit, "Bandit", 10, 10, 0);

    std::cout << HeroClapTrap << std::endl;
    std::cout << Bandit << std::endl;

    for (int i = 0; i < 10; i++) {
      HeroClapTrap.attack("Bandit");
      Bandit.takeDamage(HeroClapTrap.getAttackDamage());
    }

    std::cout << HeroClapTrap << std::endl;
    std::cout << Bandit << std::endl;
    checkClapTrap(HeroClapTrap, "HeroClapTrap", 10, 0, 0);
    checkClapTrap(Bandit, "Bandit", 10, 10, 0);
  }

  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ClapTrap Class with 11 attacks" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ClapTrap HeroClapTrap("HeroClapTrap");
    checkClapTrap(HeroClapTrap, "HeroClapTrap", 10, 10, 0);
    ClapTrap Bandit("Bandit");
    checkClapTrap(Bandit, "Bandit", 10, 10, 0);

    std::cout << HeroClapTrap << std::endl;
    std::cout << Bandit << std::endl;

    for (int i = 0; i < 11; i++) {
      HeroClapTrap.attack("Bandit");
      Bandit.takeDamage(HeroClapTrap.getAttackDamage());
    }

    std::cout << HeroClapTrap << std::endl;
    std::cout << Bandit << std::endl;
    checkClapTrap(HeroClapTrap, "HeroClapTrap", 10, 0, 0);
    checkClapTrap(Bandit, "Bandit", 10, 10, 0);
  }
  return EXIT_SUCCESS;
}