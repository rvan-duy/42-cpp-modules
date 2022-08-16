#include "DiamondTrap.hpp"

// constructors in initialization list get called from the left to the right

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  hit_points     = 100;
  energy_points  = 50;
  attack_damage  = 30;
  ClapTrap::name = "_clap_name";
  name           = "";
  std::cout << "-> (DiamondTrap) Default constructor for nameless DiamondTrap is called" << std::endl;
};

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
  hit_points     = 100;
  energy_points  = 50;
  attack_damage  = 30;
  ClapTrap::name = name + "_clap_name";
  name           = name;
  std::cout << "-> (DiamondTrap) Constructor for " << name << " is called" << std::endl;
};

DiamondTrap::~DiamondTrap() {
  if (name == "")
    std::cout << "-> (DiamondTrap) Destructor for nameless DiamondTrap is called" << std::endl;
  else
    std::cout << "-> (DiamondTrap) Destructor for " << name << " is called" << std::endl;
};

// Getters

const std::string &DiamondTrap::getName() const { return name; };

// Methods

void DiamondTrap::whoAmI() const {
  std::cout << "(DiamondTrap) Let's figure out who I am.." << std::endl;
  std::cout << "- my name is: " << name << std::endl;
  std::cout << "- my claptrap name is " << ClapTrap::name << std::endl;
};

// << overload

std::ostream &operator<<(std::ostream &out, const DiamondTrap &trap) {
  const std::string states[] = {"IDLE", "GATE_KEEPING_MODE"};
  out << "DiamondTrap (";
  out << "name:" << trap.getName() << " ";
  out << "hit_points:" << trap.getHitPoints() << " ";
  out << "energy_points:" << trap.getEnergyPoints() << " ";
  out << "attack_damage:" << trap.getAttackDamage() << " ";
  out << "state: " << states[trap.getState()] << ")";
  return out;
};
