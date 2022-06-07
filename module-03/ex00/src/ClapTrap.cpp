#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "-> Default constructor for nameless ClapTrap is called" << std::endl;
};
ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "-> Constructor for " << name << " is called" << std::endl;
}
ClapTrap::~ClapTrap() { std::cout << "-> Deconstructor for " << this->name << " is called" << std::endl; };

// TODO: implement the copy assignment operator
// ClapTrap & ClapTrap::operator=(const ClapTrap &trap) {
//     std::cout <<
// }

std::string  ClapTrap::getName() const { return this->name; };
unsigned int ClapTrap::getHitPoints() const { return this->hit_points; };
unsigned int ClapTrap::getEnergyPoints() const { return this->energy_points; };
unsigned int ClapTrap::getAttackDamage() const { return this->attack_damage; };

void         ClapTrap::attack(const std::string &target) {
          if (this->energy_points > 0) {
            std::cout << "ClapTrap " << this->name << " attacks " << target << "!" << std::endl;
            this->energy_points--;
  } else {
            std::cout << "ClapTrap " << this->name << " is out of energy points!" << std::endl;
  }
};

// what if it dies
void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;
  this->hit_points -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->energy_points > 0) {
    std::cout << "ClapTrap " << this->name << " repairs itself with " << amount << std::endl;
    this->hit_points += amount;
    this->energy_points--;
  } else {
    std::cout << "ClapTrap " << this->name << " is out of energy points!" << std::endl;
  }
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &trap) {
  out << "ClapTrap (";
  out << "name:" << trap.getName() << " ";
  out << "hit_points:" << trap.getHitPoints() << " ";
  out << "energy_points:" << trap.getEnergyPoints() << " ";
  out << "attack_damage:" << trap.getAttackDamage() << ")";
  return out;
}
