#include "Cat.hpp"

Cat::Cat() {
  std::cout << "-> (Cat) Default constructor is called" << std::endl;
  type  = "Cat";
  brain = new Brain();
}

Cat::~Cat() {
  std::cout << "-> (Cat) Destructor is called" << std::endl;
  delete brain;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
  std::cout << "-> (Cat) Copy constructor is called" << std::endl;
  brain  = new Brain();
  *brain = *cat.brain;
}

Cat &Cat::operator=(const Cat &cat) {
  std::cout << "-> (Cat) Copy assignment operator overload is called" << std::endl;
  if (this != &cat) {
    Animal::operator=(cat);
    delete brain;
    brain  = new Brain();
    *brain = *cat.brain;
  }
  return *this;
}

// Getters

Brain *Cat::getBrainPtr() const {
  return brain;
}

// Methods

void Cat::makeSound() const {
  std::cout << "* Cat meows *" << std::endl;
}
