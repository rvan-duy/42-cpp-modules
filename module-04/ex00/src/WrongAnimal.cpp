#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
  std::cout << "-> (WrongAnimal) Default constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "-> (WrongAnimal) Destructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
  std::cout << "-> (WrongAnimal) Copy constructor is called" << std::endl;
  type = animal.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
  std::cout << "-> (WrongAnimal) Copy assignment operator overload is called" << std::endl;
  if (this != &animal) {
    type = animal.type;
  }
  return *this;
}

// Getters

const std::string &WrongAnimal::getType() const {
  return type;
}

// Methods

void WrongAnimal::makeSound() const {
  std::cout << "(WrongAnimal) * Animal noises *" << std::endl;
}
