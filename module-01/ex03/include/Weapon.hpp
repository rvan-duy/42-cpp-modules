#ifndef MODULE_01_WEAPON_HPP
#define MODULE_01_WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
 public:
  Weapon();
  Weapon(const std::string& type);
  ~Weapon();

  std::string getType(void) const;
  void        setType(const std::string type);

 private:
  std::string _type;
};

#endif  // MODULE_01_WEAPON_HPP
