#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < inventory_limit; i++) {
    this->inventory[i] = NULL;
  };
  std::cout << "-> (MateriaSource) Default constructor for MateriaSource is called" << std::endl;
};

MateriaSource::~MateriaSource() {
  for (int i = 0; i < inventory_limit; i++) {
    if (this->inventory[i] != NULL) {
      delete this->inventory[i];
      this->inventory[i] = NULL;
    }
  }
  std::cout << "-> (MateriaSource) Destructor for MateriaSource is called" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource& source) {
  for (int i = 0; i < inventory_limit; i++) {
    if (source.inventory[i] != NULL) {
      this->inventory[i]  = new AMateria();
      *this->inventory[i] = *(source.inventory[i]);
    };
  };
  std::cout << "-> (MateriaSource) Copy constructor for MateriaSource is called" << std::endl;
};

MateriaSource& MateriaSource::operator=(const MateriaSource& source) {
  for (int i = 0; i < inventory_limit; i++) {
    this->inventory[i]  = new AMateria();
    *this->inventory[i] = *(source.inventory[i]);
  };
  std::cout << "-> (MateriaSource) Copy assignment operator for MateriaSource is called" << std::endl;
  return *this;
};

// Copies the AMateria and stores it in memory so it can be cloned
void MateriaSource::learnMateria(AMateria* m) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = new AMateria(m);
      std::cout << "MateriaSource learned " << m->getType() << std::endl;
      return;
    };
  };
  std::cout << "Failed to learn " << m->getType() << std::endl;
};

// 1. Look for type in inventory
// 2. if its found return a copy
// 3. if not return NULL
AMateria* createMateria(std::string const& type) {
  for (int i = 0; i < inventory_limit; i++) {
    if (inventory[i] != NULL) {
      if (inventory[i]->getType() == type) {
        return new AMateria(type);
      };
    };
  };
  return NULL;
};
