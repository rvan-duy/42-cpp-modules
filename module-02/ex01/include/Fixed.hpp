#ifndef MODULE_01_FIXED_POINT_HPP
#define MODULE_01_FIXED_POINT_HPP

#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();                               // Default constructor
  Fixed(const int value);                // Constructor with int
  Fixed(const float value);              // Constructor with float
  Fixed(const Fixed& point);             // Copy constructor
  Fixed& operator=(const Fixed& point);  // Copy assignment operator
  ~Fixed();                              // Destructor

  // Methods
  int   getRawBits() const;
  void  setRawBits(int const raw);
  float toFloat() const;
  int   toInt() const;

 private:
  static const int num_of_fractional_bits = 8;
  int              value;
};

std::ostream& operator<<(std::ostream& os, const Fixed& point);

#endif  // MODULE_02_FIXED_HPP
