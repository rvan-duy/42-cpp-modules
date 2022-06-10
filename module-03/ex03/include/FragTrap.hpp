#ifndef MODULE_03_FRAGTRAP_HPP
#define MODULE_03_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
 public:
  FragTrap();                                 // Default Constructor
  FragTrap(const std::string &name);          // Constructor with name
  ~FragTrap();                                // Destructor
  FragTrap(const FragTrap &trap);             // Copy Constructor
  FragTrap &operator=(const FragTrap &trap);  // Copy assignment operator

  // Methods
  void highFiveGuys();
};

#endif // MODULE_03_FRAGTRAP_HPP
