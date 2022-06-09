#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  this->hit_points    = FragTrap::hit_points;
  this->energy_points = ScavTrap::energy_points;
  this->attack_damage = FragTrap::attack_damage;
  std::cout << "-> (DiamondTrap) Default constructor for nameless DiamondTrap is called" << std::endl;
};

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
  this->hit_points     = FragTrap::hit_points;
  this->energy_points  = ScavTrap::energy_points;
  this->attack_damage  = FragTrap::attack_damage;
  this->ClapTrap::name = name + "_clap_name";
  this->name           = name;
  std::cout << "-> (DiamondTrap) Constructor for " << name << " is called" << std::endl;
};

DiamondTrap::~DiamondTrap() {
  std::cout << "-> (DiamondTrap) Deconstructor for " << this->name << " is called" << std::endl;
}

std::string DiamondTrap::getName() const { return this->name; }
