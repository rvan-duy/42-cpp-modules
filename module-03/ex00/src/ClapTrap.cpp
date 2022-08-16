#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "-> Default constructor for nameless ClapTrap is called" << std::endl;
};

ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "-> Constructor for " << name << " is called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "-> Deconstructor for " << name << " is called" << std::endl; };

ClapTrap::ClapTrap(const ClapTrap &trap) {
  *this = trap;
  std::cout << "-> Copy constructor for " << name << " is called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &trap) {
  name          = trap.name;
  hit_points    = trap.hit_points;
  energy_points = trap.energy_points;
  attack_damage = trap.attack_damage;
  std::cout << "-> Copy assignment constructor for " << name << " is called" << std::endl;
  return *this;
}

// Getters

std::string  ClapTrap::getName() const { return name; };

unsigned int ClapTrap::getHitPoints() const { return hit_points; };

unsigned int ClapTrap::getEnergyPoints() const { return energy_points; };

unsigned int ClapTrap::getAttackDamage() const { return attack_damage; };

// Methods

void ClapTrap::attack(const std::string &target) {
  if (energy_points > 0) {
    std::cout << "ClapTrap " << name << " attacks " << target << std::endl;
    energy_points--;
  } else {
    std::cout << "ClapTrap " << name << " is out of energy points" << std::endl;
  }
};

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << name << " takes " << amount << " damage" << std::endl;
  if (amount >= hit_points) {
    hit_points = 0;
    std::cout << "ClapTrap " << name << " dies" << std::endl;
  } else
    hit_points -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
  if (energy_points > 0) {
    std::cout << "ClapTrap " << name << " repairs itself with " << amount << std::endl;
    hit_points += amount;
    energy_points--;
  } else {
    std::cout << "ClapTrap " << name << " is out of energy points" << std::endl;
  }
}

// << overload

std::ostream &operator<<(std::ostream &out, const ClapTrap &trap) {
  out << "ClapTrap (";
  out << "name:" << trap.getName() << " ";
  out << "hit_points:" << trap.getHitPoints() << " ";
  out << "energy_points:" << trap.getEnergyPoints() << " ";
  out << "attack_damage:" << trap.getAttackDamage() << ")";
  return out;
}
