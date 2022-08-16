#include <cassert>
#include <cstdlib>

#include "ScavTrap.hpp"

static void checkTrap(const ScavTrap &trap, const std::string &name, const unsigned int hit_points,
                          const unsigned int energy_points, const unsigned int attack_damage,
                          const ScavTrap::State state) {
  assert(trap.getName() == name);
  assert(trap.getHitPoints() == hit_points);
  assert(trap.getEnergyPoints() == energy_points);
  assert(trap.getAttackDamage() == attack_damage);
  assert(trap.getState() == state);
};

int main(void) {
  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ScavTrap Class with 10 attacks" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ScavTrap hero("Hero");
    checkTrap(hero, "Hero", 100, 50, 20, ScavTrap::IDLE);
    ScavTrap bandit("Bandit");
    checkTrap(bandit, "Bandit", 100, 50, 20, ScavTrap::IDLE);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;

    for (int i = 0; i < 10; i++) {
      if (bandit.getHitPoints() == 0) break;
      hero.attack("Bandit");
      bandit.takeDamage(hero.getAttackDamage());
    }

    checkTrap(hero, "Hero", 100, 45, 20, ScavTrap::IDLE);
    checkTrap(bandit, "Bandit", 0, 50, 20, ScavTrap::IDLE);

    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;
  }

  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ScavTrap Class with guard mode" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ScavTrap hero("Hero");
    checkTrap(hero, "Hero", 100, 50, 20, ScavTrap::IDLE);

    std::cout << hero << std::endl;

    assert(hero.getState() == ScavTrap::IDLE);
    hero.guardGate();
    assert(hero.getState() == ScavTrap::GATE_KEEPING_MODE);

    std::cout << hero << std::endl;
  }

  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ScavTrap Class with copy      " << std::endl;
    std::cout << "                          constructor " << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ScavTrap hero("Hero");
    checkTrap(hero, "Hero", 100, 50, 20, ScavTrap::IDLE);

    assert(hero.getState() == ScavTrap::IDLE);
    hero.guardGate();
    assert(hero.getState() == ScavTrap::GATE_KEEPING_MODE);

    ScavTrap second_hero(hero); // manually calling copy constructor
    checkTrap(second_hero, "Hero", 100, 50, 20, ScavTrap::GATE_KEEPING_MODE);

    std::cout << hero << std::endl;
  }

  {
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing ScavTrap Class with copy      " << std::endl;
    std::cout << "                  assignment operator " << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    ScavTrap hero("Hero");
    checkTrap(hero, "Hero", 100, 50, 20, ScavTrap::IDLE);

    assert(hero.getState() == ScavTrap::IDLE);
    hero.guardGate();
    assert(hero.getState() == ScavTrap::GATE_KEEPING_MODE);

    ScavTrap second_hero;
    second_hero = hero;
    checkTrap(second_hero, "Hero", 100, 50, 20, ScavTrap::GATE_KEEPING_MODE);

    std::cout << hero << std::endl;
  }

  return EXIT_SUCCESS;
}