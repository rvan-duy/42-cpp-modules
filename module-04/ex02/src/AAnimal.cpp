#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") {
  std::cout << "-> (AAnimal) Default constructor is called" << std::endl;
}

AAnimal::~AAnimal() {
  std::cout << "-> (AAnimal) Destructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal) {
  std::cout << "-> (AAnimal) Copy constructor is called" << std::endl;
  type = animal.type;
}

AAnimal &AAnimal::operator=(const AAnimal &animal) {
  std::cout << "-> (AAnimal) Copy assignment operator is called" << std::endl;
  if (this != &animal) {
    type = animal.type;
  }
  return *this;
}

// Getters

const std::string &AAnimal::getType() const {
  return type;
}
