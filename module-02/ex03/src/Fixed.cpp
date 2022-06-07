#include "Fixed.hpp"

Fixed::Fixed() { this->value = 0; };

Fixed::Fixed(const int value) {
  this->value = value << this->num_of_fractional_bits;
}

Fixed::Fixed(const float value) {
  this->value = roundf(value * (1 << this->num_of_fractional_bits));
}

Fixed::Fixed(const Fixed &point) {
  this->value = point.value;
};

Fixed &Fixed::operator=(const Fixed &point) {
  this->value = point.getRawBits();
  return *this;
};

Fixed::~Fixed(){};

int Fixed::getRawBits() const { return this->value; };

void Fixed::setRawBits(int const raw) { this->value = raw; };

Fixed Fixed::operator+(const Fixed &f) const {
  return Fixed(this->toFloat() + f.toFloat());
};

Fixed Fixed::operator-(const Fixed &f) const {
  return Fixed(this->toFloat() - f.toFloat());
};

Fixed Fixed::operator*(const Fixed &f) const {
  return Fixed(this->toFloat() * f.toFloat());
};

Fixed Fixed::operator/(const Fixed &f) const {
  return Fixed(this->toFloat() / f.toFloat());
};

bool Fixed::operator>(const Fixed &point) const {
  return this->value > point.getRawBits();
};

bool Fixed::operator<(const Fixed &point) const {
  return this->value < point.getRawBits();
};

bool Fixed::operator>=(const Fixed &point) const {
  return this->value >= point.getRawBits();
};

bool Fixed::operator<=(const Fixed &point) const {
  return this->value <= point.getRawBits();
};

bool Fixed::operator==(const Fixed &point) const {
  return this->value == point.getRawBits();
};

bool Fixed::operator!=(const Fixed &point) const {
  return this->value != point.getRawBits();
};

Fixed &Fixed::operator++() {
  this->value++;
  return *this;
};

Fixed Fixed::operator++(int) {
  Fixed cpy = *this;
  ++*this;
  return cpy;
};

Fixed &Fixed::operator--() {
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed cpy = *this;
  --*this;
  return cpy;
};

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a < b)
    return a;
  else
    return b;
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
  if (a < b)
    return a;
  else
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a > b)
    return a;
  else
    return b;
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
  if (a > b)
    return a;
  else
    return b;
}

float Fixed::toFloat() const {
  return (float)value / (1 << this->num_of_fractional_bits);
};

int Fixed::toInt() const {
   return value >> this->num_of_fractional_bits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &point) {
  os << point.toFloat();
  return os;
};