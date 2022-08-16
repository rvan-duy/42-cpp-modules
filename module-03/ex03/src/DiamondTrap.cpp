#include "DiamondTrap.hpp"

// constructors in initialization list get called from the left to the right

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  this->hit_points     = 100;
  this->energy_points  = 50;
  this->attack_damage  = 30;
  this->ClapTrap::name = "_clap_name";
  this->name           = "";
  std::cout << "-> (DiamondTrap) Default constructor for nameless DiamondTrap is called" << std::endl;
};

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
  this->hit_points     = 100;
  this->energy_points  = 50;
  this->attack_damage  = 30;
  this->ClapTrap::name = name + "_clap_name";
  this->name           = name;
  std::cout << "-> (DiamondTrap) Constructor for " << name << " is called" << std::endl;
};

DiamondTrap::~DiamondTrap() {
  if (this->name == "")
    std::cout << "-> (DiamondTrap) Destructor for nameless DiamondTrap is called" << std::endl;
  else
    std::cout << "-> (DiamondTrap) Destructor for " << this->name << " is called" << std::endl;
};

std::string DiamondTrap::getName() const { return this->name; };

void DiamondTrap::whoAmI() const {
  std::cout << "(DiamondTrap) Let's figure out who I am.." << std::endl;
  std::cout << "- my name is: " << this->name << std::endl;
  std::cout << "- my claptrap name is " << this->ClapTrap::name << std::endl;
};

std::ostream &operator<<(std::ostream &out, const DiamondTrap &trap) {
  const std::string states[] = { "IDLE", "GATE_KEEPING_MODE" };
  out << "DiamondTrap (";
  out << "name:" << trap.getName() << " ";
  out << "hit_points:" << trap.getHitPoints() << " ";
  out << "energy_points:" << trap.getEnergyPoints() << " ";
  out << "attack_damage:" << trap.getAttackDamage() << " ";
  out << "state: " << states[trap.getState()] << ")";
  return out;
};
