#include "AMateria.hpp"

AMateria::AMateria() : type(""){}

AMateria::AMateria(std::string const& type) : type(type){}

AMateria::~AMateria(){}

AMateria::AMateria(const AMateria& material) {
  type = material.type;
}

AMateria& AMateria::operator=(const AMateria& materia) {
  if (this != &materia) {
    type = materia.type;
  }
  return *this;
}

// Getters

std::string const& AMateria::getType() const {
  return type;
}

// Methods

void AMateria::use(ICharacter& target) {
  std::cerr << "If this shows, something goes horribly wrong" << std::endl;
  (void)target;
}
