#ifndef MODULE_03_SCAVTRAP_HPP
#define MODULE_03_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
 public:
  enum State {
    IDLE,
    GATE_KEEPING_MODE
  };

  ScavTrap();                                 // Default Constructor
  ScavTrap(const std::string &name);          // Constructor with name
  ~ScavTrap();                                // Destructor
  ScavTrap(const ScavTrap &trap);             // Copy Constructor
  ScavTrap &operator=(const ScavTrap &trap);  // Copy assignment operator

  // Getters
  State getState() const;

  // Methods
  void attack(const std::string &target);
  void guardGate();

 private:
  State state;
};

std::ostream &operator<<(std::ostream &out, const ScavTrap &trap);

#endif // MODULE_03_SCAVTRAP_HPP
