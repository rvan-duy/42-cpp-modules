#ifndef MODULE_01_HUMANA_HPP
#define MODULE_01_HUMANA_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(const std::string& name, Weapon& weapon);
  ~HumanA();

  void attack(void) const;

 private:
  std::string _name;
  Weapon&     _weapon;
};

#endif  // MODULE_01_HUMANA_HPP
