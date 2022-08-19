#include "Cure.hpp"

Cure::Cure() {
  type = "cure";
};

Cure::~Cure(){};

Cure::Cure(const Cure &cure) {
  *this = cure;
};

Cure &Cure::operator=(const Cure &cure) {
  if (this != &cure) {
    AMateria::type = cure.type;
  };
  return *this;
};

// Methods

Cure *Cure::clone() const {
  return new Cure(*this);
};

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};
