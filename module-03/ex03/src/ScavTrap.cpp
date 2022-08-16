#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap(), state(IDLE) {
  std::cout << "-> (ScavTrap) Default constructor for nameless ScavTrap is called" << std::endl;
  hit_points    = 100;
  energy_points = 50;
  attack_damage = 20;
};

ScavTrap::ScavTrap(const std::string &name) : ClapTrap::ClapTrap(name), state(IDLE) {
  std::cout << "-> (ScavTrap) Constructor for " << name << " is called" << std::endl;
  hit_points    = 100;
  energy_points = 50;
  attack_damage = 20;
};

ScavTrap::~ScavTrap() { std::cout << "-> (ScavTrap) Destructor for " << name << " is called" << std::endl; };

ScavTrap::ScavTrap(const ScavTrap &trap) : ClapTrap::ClapTrap(trap) {
  std::cout << "-> (ScavTrap) Copy constructor for " << name << " is called" << std::endl;
  *this = trap;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &trap) {
  std::cout << "-> (ScavTrap) Copy assignment constructor for " << name << " is called" << std::endl;
  if (this != &trap) {
    ClapTrap::operator=(trap);  // manually calling assignment operator from base class
    state = trap.state;
  }
  return *this;
};

// Getters

ScavTrap::State ScavTrap::getState() const { return state; };

// Methods

void ScavTrap::attack(const std::string &target) {
  if (energy_points > 0) {
    std::cout << "ScavTrap " << name << " attacks " << target << std::endl;
    energy_points--;
  } else {
    std::cout << "ScavTrap " << name << " is out of energy points" << std::endl;
  }
};

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name << " is guarding the gate" << std::endl;
  state = GATE_KEEPING_MODE;
};

// << overload

std::ostream &operator<<(std::ostream &out, const ScavTrap &trap) {
  const std::string states[2] = {"IDLE", "GATE_KEEPING_MODE"};
  out << "ScavTrap (";
  out << "name:" << trap.getName() << " ";
  out << "hit_points:" << trap.getHitPoints() << " ";
  out << "energy_points:" << trap.getEnergyPoints() << " ";
  out << "attack_damage:" << trap.getAttackDamage() << " ";
  out << "state: " << states[trap.getState()] << ")";
  return out;
};
