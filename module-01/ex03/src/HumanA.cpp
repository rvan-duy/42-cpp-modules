#include "HumanA.hpp"

#include <iostream>

// HumanA::HumanA() {} <- this will cause a compilation error
HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack(void) const { std::cout << _name << " attacks with their " << _weapon.getType() << std::endl; }
