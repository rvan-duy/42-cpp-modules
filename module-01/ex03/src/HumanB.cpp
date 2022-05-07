#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(){};
HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }
void HumanB::attack(void) const { std::cout << _name << " attacks with their " << _weapon->getType() << std::endl; }