#ifndef MODULE_02_POINT_HPP
#define MODULE_02_POINT_HPP

#include "Fixed.hpp"
  
class Point {
 public:
  Point();                               // Default constructor
  Point(const float x, const float y);   // Constructor with parameters
  Point(const Point& point);             // Copy constructor
  Point& operator=(const Point& point);  // Copy assignment operator
  ~Point();                              // Destructor

  // Getters
  float getX() const;
  float getY() const;

 private:
  Fixed const x;
  Fixed const y;
};

#endif  // MODULE_02_POINT_HPP