#include "MateriaSource.hpp"

#include <cstring>

MateriaSource::MateriaSource() {
  inventory = new AMateria*[inventory_limit]();
  std::cout << "-> (MateriaSource) Default constructor for MateriaSource is called" << std::endl;
};

MateriaSource::~MateriaSource() {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] != NULL) {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
  delete inventory;
  std::cout << "-> (MateriaSource) Destructor for MateriaSource is called" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource& source) {
  for (int i = 0; i < inventory_limit; i++) {
    if (source.inventory[i] != NULL) {
      inventory[i] = source.inventory[i]->clone();
    };
  };
  std::cout << "-> (MateriaSource) Copy constructor for MateriaSource is called" << std::endl;
};

MateriaSource& MateriaSource::operator=(const MateriaSource& source) {
  for (int i = 0; i < inventory_limit; i++) {
    inventory[i] = source.inventory[i]->clone();
  };
  std::cout << "-> (MateriaSource) Copy assignment operator for MateriaSource is called" << std::endl;
  return *this;
};

void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m->clone();
      std::cout << "MateriaSource learned " << m->getType() << std::endl;
      return;
    };
  };
  std::cout << "Failed to learn " << m->getType() << std::endl;
};

// 1. Look for type in inventory
// 2. if its found return a copy with clone()
// 3. if not return NULL
AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] != NULL) {
      if (inventory[i]->getType() == type) {
        return inventory[i]->clone();
      };
    };
  };
  return NULL;
};
