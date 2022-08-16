#ifndef MODULE_03_DIAMONDTRAP_HPP
#define MODULE_03_DIAMONDTRAP_HPP

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
  const std::string &getName() const;

  // Methods
  void whoAmI() const;

 private:
  std::string name;
};

std::ostream &operator<<(std::ostream &out, const DiamondTrap &trap);

#endif  // MODULE_03_DIAMONDTRAP_HPP
