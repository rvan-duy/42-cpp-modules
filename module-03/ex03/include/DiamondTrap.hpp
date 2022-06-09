#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();                                    // Default constructor
  DiamondTrap(const std::string &name);             // Constructor with name
  ~DiamondTrap();                                   // Destructor
  DiamondTrap(const DiamondTrap &trap);             // Copy Constructor
  DiamondTrap &operator=(const DiamondTrap &trap);  // Copy assignment operator

  // Getters
  std::string getName() const;

 private:
  std::string name;
};