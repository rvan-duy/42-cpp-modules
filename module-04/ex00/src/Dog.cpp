#include "Dog.hpp"

// Note: you cannot set initialize base class members from the initialization list in the derived class
Dog::Dog() {
  this->type = "Dog";
  std::cout << "-> (Dog) Default constructor for Dog is called" << std::endl;
};

Dog::~Dog() { std::cout << "-> (Dog) Destructor for Dog is called" << std::endl; };

Dog::Dog(const Dog &dog) {
  this->type = dog.type;
  std::cout << "-> (Dog) Copy assignment constructor for Dog is called" << std::endl;
};

Dog &Dog::operator=(const Dog &dog) {
  this->type = dog.type;
  std::cout << "(Dog) Copy assignment constructor for Dog is called" << std::endl;
  return *this;
};

void        Dog::makeSound() const { std::cout << "-> (Dog) * Dog barks *" << std::endl; }
