#ifndef MODULE_00_ZOMBIE_HPP
#define MODULE_00_ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
 public:
  // Default constructor
  Zombie();

  // Constructor
  Zombie(const std::string name);

  // Destructor
  ~Zombie();

  // Methods
  void announce(void);

  // Getters
  std::string getName(void) const;

  // Setters
  void setName(std::string name);

 private:
  // Attributes
  std::string _name;  // Name of the zombie
};

#endif  // MODULE_00_ZOMBIE_HPP
