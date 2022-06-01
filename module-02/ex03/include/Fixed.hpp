#ifndef MODULE_02_FIXED_HPP
#define MODULE_02_FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();                               // Default constructor
  Fixed(const int value);                // Constructor from int
  Fixed(const float value);              // Constructor from float
  Fixed(const Fixed& point);             // Copy constructor
  Fixed& operator=(const Fixed& point);  // Copy assignment operator
  ~Fixed();                              // Destructor

  // Getters
  int getRawBits() const;

  // Setters
  void setRawBits(int const raw);

  // Arithmetic operators
  Fixed operator+(const Fixed& f) const;
  Fixed operator-(const Fixed& f) const;
  Fixed operator*(const Fixed& f) const;
  Fixed operator/(const Fixed& f) const;

  // Comparison operators
  bool operator>(const Fixed& point) const;
  bool operator<(const Fixed& point) const;
  bool operator>=(const Fixed& point) const;
  bool operator<=(const Fixed& point) const;
  bool operator==(const Fixed& point) const;
  bool operator!=(const Fixed& point) const;

  // Increment and decrement operators
  Fixed  operator++(int);  // Postfix increment
  Fixed& operator++();     // Prefix increment
  Fixed  operator--(int);  // Postfix decrement
  Fixed& operator--();     // Prefix decrement

  // Static methods
  static Fixed& min(Fixed& a, Fixed& b);
  static Fixed min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static Fixed max(const Fixed& a, const Fixed& b);

  // Other methods
  float toFloat() const;
  int   toInt() const;

 private:
  static const int num_of_fractional_bits = 8;
  int              value;
};

// << operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& point);

#endif  // MODULE_02_FIXED_HPP
