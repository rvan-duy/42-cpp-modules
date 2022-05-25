#ifndef MODULE_01_FIXED_POINT_HPP
#define MODULE_01_FIXED_POINT_HPP

#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& point);
  void operator=(const Fixed& point);
  ~Fixed();

  int   getRawBits() const;
  void  setRawBits(int const raw);
  float toFloat() const;
  int   toInt() const;

 private:
  static const int num_of_fractional_bits = 8;
  int              value;
};

std::ostream& operator<<(std::ostream& os, const Fixed& point);

#endif  // MODULE_01_FIXED_POINT_HPP
