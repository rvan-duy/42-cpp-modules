#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(){};
HumanB::HumanB(const std::string name) : name(name), weapon(NULL){};
HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }
void HumanB::attack(void) const { std::cout << name << " attacks with their " << weapon->getType() << std::endl; };
