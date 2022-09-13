#include "Cure.hpp"

Cure::Cure() {
  type = "cure";
}

Cure::~Cure() {}

Cure::Cure(const Cure &cure) : AMateria(cure) {}

Cure &Cure::operator=(const Cure &cure) {
  if (this != &cure) {
    AMateria::operator=(cure);
  }
  return *this;
}

// Methods

Cure *Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
