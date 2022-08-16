#include <cassert>
#include <cstdlib>

#include "FragTrap.hpp"

static void checkTrap(FragTrap &trap, const std::string &name, const unsigned int hit_points,
                          const unsigned int energy_points, const unsigned int attack_damage) {
  assert(trap.getName() == name);
  assert(trap.getHitPoints() == hit_points);
  assert(trap.getEnergyPoints() == energy_points);
  assert(trap.getAttackDamage() == attack_damage);
}

int main(void) {
  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing FragTrap Class with 10 attacks" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    FragTrap hero("Hero");
    checkTrap(hero, "Hero", 100, 100, 30);
    FragTrap bandit("Bandit");
    checkTrap(bandit, "Bandit", 100, 100, 30);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;

    for (int i = 0; i < 10; i++) {
      if (bandit.getHitPoints() == 0) break;
      hero.attack("Bandit");
      bandit.takeDamage(hero.getAttackDamage());
    }

    checkTrap(hero, "Hero", 100, 96, 30);
    checkTrap(bandit, "Bandit", 0, 100, 30);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;
  }

  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing FragTrap Class with high fives" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    FragTrap hero("Hero");
    checkTrap(hero, "Hero", 100, 100, 30);

    std::cout << hero << std::endl;

    hero.highFiveGuys();
  }

  return EXIT_SUCCESS;
}