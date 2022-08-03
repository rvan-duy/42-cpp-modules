#ifndef MODULE_01_HUMANA_HPP
#define MODULE_01_HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(const std::string& name, Weapon& weapon);
  ~HumanA();

  void attack(void) const;

 private:
  std::string name;
  Weapon&     weapon;
};

#endif  // MODULE_01_HUMANA_HPP
