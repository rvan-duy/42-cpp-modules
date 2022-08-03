#include "HumanA.hpp"

#include <iostream>

// HumanA::HumanA() {} <- this will cause a compilation error
HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon){};
HumanA::~HumanA(){};

void HumanA::attack(void) const { std::cout << name << " attacks with their " << weapon.getType() << std::endl; };
