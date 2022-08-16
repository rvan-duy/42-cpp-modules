#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "-> (ClapTrap) Default constructor for nameless ClapTrap is called" << std::endl;
};

ClapTrap::ClapTrap(const std::string &name) : name(name), hit_points(10), energy_points(10), attack_damage(0) {
  std::cout << "-> (ClapTrap) Constructor for " << name << " is called" << std::endl;
}

ClapTrap::~ClapTrap() { std::cout << "-> (ClapTrap) Destructor for " << this->name << " is called" << std::endl; };

ClapTrap::ClapTrap(const ClapTrap &trap)
    : name(trap.name),
      hit_points(trap.hit_points),
      energy_points(trap.energy_points),
      attack_damage(trap.attack_damage) {
  std::cout << "-> (ClapTrap) Copy constructor for " << this->name << " is called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &trap) {
  this->name          = trap.name;
  this->hit_points    = trap.hit_points;
  this->energy_points = trap.energy_points;
  this->attack_damage = trap.attack_damage;
  std::cout << "-> (ClapTrap) Copy assignment constructor for " << this->name << " is called" << std::endl;
  return *this;
}

std::string  ClapTrap::getName() const { return this->name; };

unsigned int ClapTrap::getHitPoints() const { return this->hit_points; };

unsigned int ClapTrap::getEnergyPoints() const { return this->energy_points; };

unsigned int ClapTrap::getAttackDamage() const { return this->attack_damage; };

void         ClapTrap::attack(const std::string &target) {
          if (this->energy_points > 0) {
            std::cout << "ClapTrap " << this->name << " attacks " << target << std::endl;
            this->energy_points--;
  } else {
            std::cout << "ClapTrap " << this->name << " is out of energy points" << std::endl;
  }
};

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << this->name << " takes " << amount << " damage" << std::endl;
  if (amount >= this->hit_points) {
    this->hit_points = 0;
    std::cout << "ClapTrap " << this->name << " dies" << std::endl;
  } else
    this->hit_points -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->energy_points > 0) {
    std::cout << "ClapTrap " << this->name << " repairs itself with " << amount << std::endl;
    this->hit_points += amount;
    this->energy_points--;
  } else {
    std::cout << "ClapTrap " << this->name << " is out of energy points" << std::endl;
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
