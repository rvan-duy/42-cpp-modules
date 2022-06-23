#include "Cure.hpp"

Cure::Cure() {
  this->type = "cure";
  std::cout << "-> (Cure) Default constructor for Cure is called" << std::endl;
};

Cure::~Cure() { std::cout << "-> (Cure) Destructor for Cure is called" << std::endl; };

Cure::Cure(const Cure &cure) {
  this->type = cure.type;
  std::cout << "-> (Cure) Copy constructor for Cure is called" << std::endl;
};

Cure &Cure::operator=(const Cure &cure) {
  this->type = cure.type;
  std::cout << "(Cure) Copy assignment operator for Cure is called" << std::endl;
  return *this;
};

// Clones the cure and returns it
Cure *Cure::clone() {
  Cure new_cure;

  return &new_cure;
};

// probably replace with getname func
void Cure::use(ICharacter &target) { std::cout << "* heals " << target.name << "'s wounds *" << std::endl; };
