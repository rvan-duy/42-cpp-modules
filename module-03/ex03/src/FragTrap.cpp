#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  this->hit_points    = 100;
  this->energy_points = 100;
  this->attack_damage = 30;
  std::cout << "-> (FragTrap) Default constructor for nameless FragTrap is called" << std::endl;
};

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  this->hit_points    = 100;
  this->energy_points = 100;
  this->attack_damage = 30;
  std::cout << "-> (FragTrap) Constructor for " << name << " is called" << std::endl;
};

FragTrap::~FragTrap() { std::cout << "-> (FragTrap) Deconstructor for " << this->name << " is called" << std::endl; };

FragTrap::FragTrap(const FragTrap &trap) : ClapTrap(trap) {
  std::cout << "-> (FragTrap) Copy constructor for " << this->name << " is called" << std::endl;
};

FragTrap &FragTrap::operator=(const FragTrap &trap) {
  this->name          = trap.name;
  this->hit_points    = trap.hit_points;
  this->energy_points = trap.energy_points;
  this->attack_damage = trap.attack_damage;
  std::cout << "-> (FragTrap) Copy assignment constructor for " << this->name << " is called" << std::endl;
  return *this;
};

void FragTrap::highFiveGuys() {
    std::cout << "-> (FragTrap) " << this->name << " is requesting high fives.." << std::endl;
}
