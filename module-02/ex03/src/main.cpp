#include <cstdlib>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int  main(void) {
   Point a(0, 0);
   Point b(0, 1);
   Point c(1, 0);
   Point point(0.5, 0.5);
   Point point2(2.0, 2.0);

   if (bsp(a, b, c, point)) {
     std::cout << "The first point is inside the triangle" << std::endl;
  } else {
     std::cout << "The first point is outside the triangle" << std::endl;
  };

   if (bsp(a, b, c, point2)) {
     std::cout << "The second point is inside the triangle" << std::endl;
  } else {
     std::cout << "The second point is outside the triangle" << std::endl;
  };
   return EXIT_SUCCESS;
};
