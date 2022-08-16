#ifndef MODULE_03_CLAPTRAP_HPP
#define MODULE_03_CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap();                                 // Default Constructor
  ClapTrap(const std::string &name);          // Constructor with name
  ~ClapTrap();                                // Destructor
  ClapTrap(const ClapTrap &trap);             // Copy Constructor
  ClapTrap &operator=(const ClapTrap &trap);  // Copy assignment operator

  // Getters
  const std::string &getName() const;
  unsigned int       getHitPoints() const;
  unsigned int       getEnergyPoints() const;
  unsigned int       getAttackDamage() const;

  // Methods
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  std::string  name;
  unsigned int hit_points;
  unsigned int energy_points;
  unsigned int attack_damage;
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &trap);

#endif  // MODULE_03_CLAPTRAP_HPP
