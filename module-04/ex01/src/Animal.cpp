#include "Animal.hpp"

Animal::Animal() : type("") {
  std::cout << "-> (Animal) Default constructor is called" << std::endl;
}

Animal::~Animal() {
  std::cout << "-> (Animal) Destructor is called" << std::endl;
}

Animal::Animal(const Animal &animal) {
  std::cout << "-> (Animal) Copy constructor is called" << std::endl;
  type = animal.type;
}

Animal &Animal::operator=(const Animal &animal) {
  std::cout << "-> (Animal) Copy assignment operator is called" << std::endl;
  if (this != &animal) {
    type = animal.type;
  }
  return *this;
}

// Getters

const std::string &Animal::getType() const {
  return type;
}

// Methods

void Animal::makeSound() const {
  std::cout << "(Animal) * Animal noises *" << std::endl;
}
