#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap::ClapTrap() {
  std::cout << "-> (FragTrap) Default constructor for nameless FragTrap is called" << std::endl;
  hit_points    = 100;
  energy_points = 100;
  attack_damage = 30;
};

FragTrap::FragTrap(const std::string &name) : ClapTrap::ClapTrap(name) {
  std::cout << "-> (FragTrap) Constructor for " << name << " is called" << std::endl;
  hit_points    = 100;
  energy_points = 100;
  attack_damage = 30;
};

FragTrap::~FragTrap() { std::cout << "-> (FragTrap) Destructor for " << name << " is called" << std::endl; };

FragTrap::FragTrap(const FragTrap &trap) : ClapTrap::ClapTrap(trap) {
  std::cout << "-> (FragTrap) Copy constructor for " << name << " is called" << std::endl;
  *this = trap;
};

FragTrap &FragTrap::operator=(const FragTrap &trap) {
  if (this != &trap) {
    ClapTrap::operator=(trap); // manually calling assignment operator from base class
  }
  std::cout << "-> (FragTrap) Copy assignment constructor for " << name << " is called" << std::endl;
  return *this;
};

void FragTrap::highFiveGuys() {
    std::cout << "-> (FragTrap) " << name << " is requesting high fives.." << std::endl;
};
