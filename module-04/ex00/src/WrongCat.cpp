#include "WrongCat.hpp"

WrongCat::WrongCat() {
  std::cout << "-> (WrongCat) Default constructor is called" << std::endl;
  type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "-> (WrongCat) Destructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat) {
  std::cout << "-> (WrongCat) Copy constructor is called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
  std::cout << "-> (WrongCat) Copy assignment operator overload is called" << std::endl;
  if (this != &cat) {
    WrongAnimal::operator=(cat);
  }
  return *this;
}

// Methods

void WrongCat::makeSound() const {
  std::cout << "(WrongCat) * Cat meows *" << std::endl;
}
