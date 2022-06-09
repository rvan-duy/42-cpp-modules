#include <cassert>
#include <cstdlib>

#include "FragTrap.hpp"

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
    std::cout << "Testing FragTrap Class with 10 attacks" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    FragTrap hero("Hero");
    checkClapTrap(hero, "Hero", 100, 100, 30);
    FragTrap bandit("Bandit");
    checkClapTrap(bandit, "Bandit", 100, 100, 30);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;

    for (int i = 0; i < 10; i++) {
      if (bandit.getHitPoints() == 0) break;
      hero.attack("Bandit");
      bandit.takeDamage(hero.getAttackDamage());
    }

    checkClapTrap(hero, "Hero", 100, 96, 30);
    checkClapTrap(bandit, "Bandit", 0, 100, 30);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;
  }

  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing FragTrap Class with high fives" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    FragTrap hero("Hero");
    checkClapTrap(hero, "Hero", 100, 100, 30);

    std::cout << hero << std::endl;
  
    hero.highFiveGuys();
  }

  return EXIT_SUCCESS;
}