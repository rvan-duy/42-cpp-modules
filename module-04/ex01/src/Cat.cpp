#include "Cat.hpp"

Cat::Cat() {
  this->type = "Cat";
  std::cout << "-> (Cat) Default constructor for Cat is called" << std::endl;
};

Cat::~Cat() { std::cout << "-> (Cat) Destructor for Cat is called" << std::endl; };

Cat::Cat(const Cat &cat) : Animal(cat) {
  this->type = cat.type;
  std::cout << "-> (Cat) Copy assignment constructor for Cat is called" << std::endl;
};

Cat &Cat::operator=(const Cat &cat) {
  this->type = cat.type;
  std::cout << "(Cat) Copy assignment constructor for Cat is called" << std::endl;
  return *this;
};

void        Cat::makeSound() const { std::cout << "-> (Cat) * Cat meows *" << std::endl; }
