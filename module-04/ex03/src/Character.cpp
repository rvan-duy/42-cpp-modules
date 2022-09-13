#include "Character.hpp"

Character::Character() : name("") {
  for (int i = 0; i < inventory_limit; i++) {
    inventory[i] = NULL;
  }
}

Character::Character(const std::string& name) : name(name) {
  for (int i = 0; i < inventory_limit; i++) {
    inventory[i] = NULL;
  }
}

Character::~Character() {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] != NULL) {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
}

Character::Character(const Character& character) {
  name = character.name;
  for (int i = 0; i < inventory_limit; i++) {
    if (character.inventory[i] != NULL) {
      inventory[i] = character.inventory[i]->clone();
    } else {
      inventory[i] = NULL;
    }
  }
}

Character& Character::operator=(const Character& character) {
  if (this != &character) {
    name = character.name;
    for (int i = 0; i < inventory_limit; i++) {
      if (character.inventory[i] != NULL) {
        inventory[i] = character.inventory[i]->clone();
      } else {
        inventory[i] = NULL;
      }
    }
  }
  return *this;
}

// Getters

std::string const& Character::getName() const {
  return name;
}

AMateria* Character::getItem(int idx) const {
  return inventory[idx];
}

// Methods

void Character::equip(AMateria* m) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m;
      std::cout << name << " equipped " << m->getType() << std::endl;
      return;
    }
  }
  std::cout << "Failed to add " << m->getType() << " to inventory of " << name << std::endl;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= inventory_limit) {
    std::cout << name << ": index is out of bound (" << idx << ")" << std::endl;
    return;
  }
  if (inventory[idx] == NULL) {
    std::cout << name << ": there is nothing to unequip (" << idx << ")" << std::endl;
    return;
  }
  std::cout << name << " successfully unequipped " << inventory[idx]->getType() << std::endl;
  inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= inventory_limit) {
    std::cout << "(" << name << " - use) index is out of bound (" << idx << ")" << std::endl;
    return;
  }
  if (inventory[idx] == NULL) {
    std::cout << "(" << name << " - use) there is nothing to use (" << idx << ")" << std::endl;
    return;
  }
  inventory[idx]->use(target);
}
