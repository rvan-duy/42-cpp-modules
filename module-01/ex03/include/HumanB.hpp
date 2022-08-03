#ifndef MODULE_01_HUMANB_HPP
#define MODULE_01_HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
 public:
  HumanB();
  HumanB(const std::string name);
  ~HumanB();

  void setWeapon(Weapon& weapon);
  void attack(void) const;

 private:
  std::string name;
  Weapon*     weapon;
};

#endif  // MODULE_01_HUMANB_HPP
