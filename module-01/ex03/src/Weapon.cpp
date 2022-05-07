#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon() {}
Weapon::Weapon(const std::string& type) : _type(type) {}
Weapon::~Weapon() {}

std::string Weapon::getType(void) const { return this->_type; }
void        Weapon::setType(std::string type) { _type = type; }
