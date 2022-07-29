#include "Cure.hpp"

Cure::Cure() {
  this->type = "cure";
  std::cout << "-> (Cure) Default constructor for Cure is called" << std::endl;
};

Cure::~Cure() { std::cout << "-> (Cure) Destructor for Cure is called" << std::endl; };

Cure::Cure(const Cure &cure) : AMateria(cure) {
  this->type = cure.type;
  std::cout << "-> (Cure) Copy constructor for Cure is called" << std::endl;
};

Cure &Cure::operator=(const Cure &cure) {
  this->type = cure.type;
  std::cout << "(Cure) Copy assignment operator for Cure is called" << std::endl;
  return *this;
};

// Allocates new object with this as content
Cure *Cure::clone() const { return new Cure(*this); };

void  Cure::use(ICharacter &target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; };
