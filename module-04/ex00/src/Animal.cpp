#include "Animal.hpp"

Animal::Animal() : type("") {
  std::cout << "-> (Animal) Default constructor for nameless Animal is called" << std::endl;
};

Animal::~Animal() { std::cout << "-> (Animal) Destructor for " << this->type << " is called" << std::endl; };

Animal::Animal(const Animal &animal) : type(animal.type) {
  std::cout << "-> (Animal) Copy assignment constructor for " << this->type << " is called" << std::endl;
};

Animal &Animal::operator=(const Animal &animal) {
  this->type = animal.type;
  std::cout << "-> (Animal) Copy assignment constructor for " << this->type << " is called" << std::endl;
  return *this;
};

std::string Animal::getType() const { return this->type; };

void        Animal::makeSound() const { std::cout << "-> (Animal) * Animal noises *" << std::endl; }
