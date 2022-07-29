#include "Character.hpp"

Character::Character() {
  for (int i = 0; i < inventory_limit; i++) {
    this->inventory[i] = NULL;
  };
  std::cout << "-> (Character) Default constructor for Character is called" << std::endl;
};

Character::Character(const std::string& name) : name(name) {
  for (int i = 0; i < inventory_limit; i++) {
    this->inventory[i] = NULL;
  };
  std::cout << "-> (Character) Constructor with name for Character is called" << std::endl;
};

Character::~Character() {
  for (int i = 0; i < inventory_limit; i++) {
    if (this->inventory[i] != NULL) {
      delete this->inventory[i];
      this->inventory[i] = NULL;
    }
  }
  std::cout << "-> (Character) Destructor for Character is called" << std::endl;
};

Character::Character(const Character& character) {
  for (int i = 0; i < inventory_limit; i++) {
    if (character.inventory[i] != NULL) {
      inventory[i] = character.inventory[i]->clone();
    };
  };
  std::cout << "-> (Character) Copy constructor for Character is called" << std::endl;
};

Character& Character::operator=(const Character& character) {
  for (int i = 0; i < inventory_limit; i++) {
    if (character.inventory[i] != NULL) {
      inventory[i] = character.inventory[i]->clone();
    };
  };
  std::cout << "-> (Character) Copy assignment operator for Character is called" << std::endl;
  return *this;
};

std::string const& Character::getName() const { return this->name; };

AMateria*          Character::getItem(int idx) const { return this->inventory[idx]; };

// Adds AMateria address to this->inventory
// 1. Look for the first available spot (not NULL)
// 2. Add it
void Character::equip(AMateria* m) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m;
      std::cout << this->name << " equipped " << m->getType() << std::endl;  // TODO better message
      return;
    };
  };
  std::cout << "Failed to add " << m->getType() << " to inventory of " << this->name << std::endl;
};

// Remove AMateria address from this->inventory on the given index
// 1. Check if index is in bounds of inventory
// 2. Check if something is on index
// 3. Remove it
void Character::unequip(int idx) {
  if (idx < 0 || idx >= this->inventory_limit) {
    std::cout << "(" << this->name << " - unequip) index is out of bound (" << idx << ")" << std::endl;
    return;
  };
  if (this->inventory[idx] == NULL) {
    std::cout << "(" << this->name << " - unequip) there is nothing to unequip (" << idx << ")" << std::endl;
    return;
  };
  std::cout << "(" << this->name << " - unequip) successfully unequipped " << this->inventory[idx]->getType()
            << std::endl;
  this->inventory[idx] = NULL;
};

// Use AMateria on given index against given target
// 1. Check if index is in bounds of inventory
// 2. Check if target exists
// 3. Maybe more checks? is target alive?
// 4. Use the item
void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= this->inventory_limit) {
    std::cout << "(" << this->name << " - use) index is out of bound (" << idx << ")" << std::endl;
    return;
  };
  if (this->inventory[idx] == NULL) {
    std::cout << "(" << this->name << " - use) there is nothing to use (" << idx << ")" << std::endl;
    return;
  };
  this->inventory[idx]->use(target);
};
