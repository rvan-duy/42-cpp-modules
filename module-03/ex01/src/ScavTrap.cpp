#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap(), state(IDLE) {
  hit_points    = 100;
  energy_points = 50;
  attack_damage = 20;
  std::cout << "-> (ScavTrap) Default constructor for nameless ScavTrap is called" << std::endl;
};

ScavTrap::ScavTrap(const std::string &name) : ClapTrap::ClapTrap(name), state(IDLE) {
  hit_points    = 100;
  energy_points = 50;
  attack_damage = 20;
  std::cout << "-> (ScavTrap) Constructor for " << name << " is called" << std::endl;
};

ScavTrap::~ScavTrap() { std::cout << "-> (ScavTrap) Destructor for " << name << " is called" << std::endl; };

ScavTrap::ScavTrap(const ScavTrap &trap) : ClapTrap::ClapTrap(trap) {
  std::cout << "-> (ScavTrap) Copy constructor for " << name << " is called" << std::endl;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &trap) {
  if (this != &trap) {
    ClapTrap::operator=(trap);  // manually calling assignment operator from base class
    state = trap.state;
  }
  std::cout << "-> (ScavTrap) Copy assignment constructor for " << name << " is called" << std::endl;
  return *this;
};

// Getters

ScavTrap::State ScavTrap::getState() const { return state; };

// Methods

void ScavTrap::guardGate() {
  state = GATE_KEEPING_MODE;
  std::cout << "ScavTrap " << name << " is guarding the gate" << std::endl;
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
