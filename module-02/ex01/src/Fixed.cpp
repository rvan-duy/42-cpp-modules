#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value(value << num_of_fractional_bits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value(value * (1 << this->num_of_fractional_bits)) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& point) : value(point.value) {
  std::cout << "Copy constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& point) {
  std::cout << "Copy assignment operator called" << std::endl;
  value = point.value;
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

// Methods

int Fixed::getRawBits() const {
  return this->value;
}

void Fixed::setRawBits(int const raw) {
  this->value = raw;
}

float Fixed::toFloat() const {
  return (float)value / (1 << this->num_of_fractional_bits);
}

int Fixed::toInt() const {
  return value >> this->num_of_fractional_bits;
}

// << overload

std::ostream& operator<<(std::ostream& os, const Fixed& point) {
  os << point.toFloat();
  return os;
}