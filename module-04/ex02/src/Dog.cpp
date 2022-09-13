#include "Dog.hpp"

Dog::Dog() {
  std::cout << "-> (Dog) Default constructor is called" << std::endl;
  type = "Dog";
  brain = new Brain();
}

Dog::~Dog() {
  std::cout << "-> (Dog) Destructor is called" << std::endl;
  delete brain;
}

Dog::Dog(const Dog &dog) : AAnimal(dog) {
  std::cout << "-> (Dog) Copy constructor is called" << std::endl;
  *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "-> (Dog) Copy assignment operator overload is called" << std::endl;
  if (this != &dog) {
    AAnimal::operator=(dog);
    brain = new Brain(*dog.brain);
  }
  return *this;
}

// Methods

void Dog::makeSound() const {
  std::cout << "* Dog barks *" << std::endl;
}
