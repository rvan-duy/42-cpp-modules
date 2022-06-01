#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->value = 0;
};

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  this->value = value << this->num_of_fractional_bits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  this->value = roundf(value * (1 << this->num_of_fractional_bits));
}

Fixed::Fixed(const Fixed& point) {
  std::cout << "Copy constructor called" << std::endl;
  *this = point;
};

void Fixed::operator=(const Fixed& point) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->value = point.getRawBits();
};

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; };

int           Fixed::getRawBits() const { return this->value; };

void          Fixed::setRawBits(int const raw) { this->value = raw; };

float         Fixed::toFloat() const { return (float)value / (1 << this->num_of_fractional_bits); };

int           Fixed::toInt() const { return value >> this->num_of_fractional_bits; };

std::ostream& operator<<(std::ostream& os, const Fixed& point) {
  os << point.toFloat();
  return os;
};