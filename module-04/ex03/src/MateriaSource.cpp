#include "MateriaSource.hpp"

#include <cstring>

MateriaSource::MateriaSource() {
  inventory = new AMateria*[inventory_limit]();
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] != NULL) {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
  delete inventory;
}

MateriaSource::MateriaSource(const MateriaSource& source) {
  inventory = new AMateria*[inventory_limit]();
  for (int i = 0; i < inventory_limit; i++) {
    if (source.inventory[i] != NULL) {
      inventory[i] = source.inventory[i]->clone();
    } else {
      inventory[i] = NULL;
    }
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& source) {
  if (this != &source) {
    delete inventory;
    inventory = new AMateria*[inventory_limit]();
    for (int i = 0; i < inventory_limit; i++) {
      if (source.inventory[i] != NULL) {
        inventory[i] = source.inventory[i]->clone();
      } else {
        inventory[i] = NULL;
      }
    }
  }
  return *this;
}

// Methods

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m->clone();
      std::cout << "MateriaSource learned " << m->getType() << std::endl;
      return;
    }
  }
  std::cout << "Failed to learn " << m->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] != NULL) {
      if (inventory[i]->getType() == type) {
        return inventory[i]->clone();
      }
    }
  }
  std::cout << "Failed to create " << type << std::endl;
  return NULL;
}
