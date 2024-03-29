#include "Fixed.hpp"

Fixed::Fixed() : value(0) { std::cout << "Default constructor called" << std::endl; };
Fixed::Fixed(const Fixed& point) : value(point.value) { std::cout << "Copy constructor called" << std::endl; };
Fixed& Fixed::operator=(const Fixed& point) {
  std::cout << "Copy assignment operator called" << std::endl;
  value = point.value;
  return *this;
};
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; };

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return value;
};

void Fixed::setRawBits(int const raw) { value = raw; };
