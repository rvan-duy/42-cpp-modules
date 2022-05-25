#include "FixedPoint.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->value = 0;
};

Fixed::Fixed(const Fixed& point) {
  std::cout << "Copy constructor called" << std::endl;
  *this = point;
};

void Fixed::operator=(const Fixed& point) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->value = point.getRawBits();
};

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; };

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->value;
};

void Fixed::setRawBits(int const raw) { this->value = raw; };
