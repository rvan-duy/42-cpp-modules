#include "Weapon.hpp"

#include <iostream>

Weapon::Weapon() {}
Weapon::Weapon(const std::string& type) : type(type) {}
Weapon::~Weapon() {}

const std::string& Weapon::getType(void) const { return this->type; }
void               Weapon::setType(std::string type) { this->type = type; }
