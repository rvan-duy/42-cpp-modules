#include "Cat.hpp"

Cat::Cat() {
  std::cout << "-> (Cat) Default constructor is called" << std::endl;
  type = "Cat";
}

Cat::~Cat() {
  std::cout << "-> (Cat) Destructor is called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
  std::cout << "-> (Cat) Copy constructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
  std::cout << "-> (Cat) Copy assignment operator overload is called" << std::endl;
  if (this != &cat) {
    Animal::operator=(cat);
  }
  return *this;
}

// Methods

void Cat::makeSound() const {
  std::cout << "(Cat) * Cat meows *" << std::endl;
}
