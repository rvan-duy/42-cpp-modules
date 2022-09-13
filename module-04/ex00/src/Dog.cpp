#include "Dog.hpp"

Dog::Dog() {
  std::cout << "-> (Dog) Default constructor is called" << std::endl;
  type = "Dog";
}

Dog::~Dog() {
  std::cout << "-> (Dog) Destructor for Dog is called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
  std::cout << "-> (Dog) Copy constructor is called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "-> (Dog) Copy assignment operator overload is called" << std::endl;
  if (this != &dog) {
    Animal::operator=(dog);
  }
  return *this;
}

// Methods

void Dog::makeSound() const {
  std::cout << "(Dog) * Dog barks *" << std::endl;
}
