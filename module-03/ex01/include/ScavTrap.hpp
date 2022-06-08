#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
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
  void guardGate();

 private:
  State state;
};
