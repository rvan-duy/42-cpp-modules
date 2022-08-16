#include <cassert>
#include <cstdlib>

#include "DiamondTrap.hpp"

static void checkDiamondTrap(const DiamondTrap& trap, const std::string& name, const unsigned int hit_points,
                             const unsigned int energy_points, const unsigned int attack_damage,
                             const DiamondTrap::State state) {
  assert(trap.ScavTrap::ClapTrap::getName() == name + "_clap_name");
  assert(trap.FragTrap::ClapTrap::getName() == name + "_clap_name");
  assert(trap.getName() == name);
  assert(trap.getHitPoints() == hit_points);
  assert(trap.getEnergyPoints() == energy_points);
  assert(trap.getAttackDamage() == attack_damage);
  assert(trap.getState() == state);
};

int main(void) {
  {
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Testing DiamondTrap going on an adventure" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    // Initializing hero with DiamondTrap class
    DiamondTrap hero("Hero");
    checkDiamondTrap(hero, "Hero", 100, 50, 30, DiamondTrap::IDLE);

    // Initializing bandit with ClapTrap class
    ClapTrap bandit("bandit");

    // Printing
    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;

    // Hero is attacking the bandit
    hero.attack("bandit");  // hero loses 1 energy, inherited from ScavTrap
    bandit.takeDamage(30);  // bandit takes 30 damage, inherited from ClapTrap

    // Bandit is retaliating
    bandit.attack("Hero");  // bandit loses 1 energy, inherited from ClapTrap
    hero.takeDamage(0);     // hero takes 0 damage, inherited from ClapTrap

    // Here goes into guard mode
    hero.guardGate();  // this is inherited from ScavTrap

    // Asking the right quests
    hero.whoAmI();  // from DiamondTrap

    checkDiamondTrap(hero, "Hero", 100, 49, 30, DiamondTrap::GATE_KEEPING_MODE);

    // Printing
    std::cout << hero << std::endl;
    std::cout << bandit << std::endl;
  }

  {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Basic tests with default constructor" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    DiamondTrap nameless;
    checkDiamondTrap(nameless, "", 100, 50, 30, DiamondTrap::IDLE);
  }

  {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Testing DiamondTrap copy constructor" << std::endl;
    std::cout << "     and copy assignment operator   " << std::endl;
    std::cout << "------------------------------------" << std::endl;

    DiamondTrap hero("Hero");
    checkDiamondTrap(hero, "Hero", 100, 50, 30, DiamondTrap::IDLE);

    hero.guardGate();

    DiamondTrap second_hero = hero;
    checkDiamondTrap(second_hero, "Hero", 100, 50, 30, DiamondTrap::GATE_KEEPING_MODE);

    DiamondTrap third_hero(hero);
    checkDiamondTrap(third_hero, "Hero", 100, 50, 30, DiamondTrap::GATE_KEEPING_MODE);
  }
  return EXIT_SUCCESS;
};
