#ifndef MODULE_01_FIXED_POINT_HPP
#define MODULE_01_FIXED_POINT_HPP

#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& point);
  Fixed& operator=(const Fixed& point);
  ~Fixed();

  int  getRawBits() const;
  void setRawBits(int const raw);

 private:
  static const int num_of_fractional_bits = 8;
  int              value;
};

#endif  // MODULE_02_FIXED_HPP
