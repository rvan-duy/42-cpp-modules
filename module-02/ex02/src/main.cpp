#include <cstdlib>

#include "Fixed.hpp"

int main(void) {
  // Testing:
  // 1. Default constructor
  // 2. Constructor from int
  // 3. Constructor from float
  // 4. Copy constructor
  // 5. Copy assignment operator
  {
    Fixed a;        // Default constructor
    Fixed b(10);    // Constructor from int
    Fixed c(5.5f);  // Constructor from float
    Fixed d(b);     // Copy constructor
    Fixed e = d;    // Copy assignment operator

    std::cout << "a: " << a.toFloat() << std::endl;
    std::cout << "b: " << b.toFloat() << std::endl;
    std::cout << "c: " << c.toFloat() << std::endl;
    std::cout << "d: " << d.toFloat() << std::endl;
    std::cout << "e: " << e.toFloat() << std::endl;
  }

  // Testing:
  // 1. Arithmetic operators (+, -, *, /)
  {
    Fixed f(3.14f);
    Fixed g(2.71f);
    Fixed h, i, j, k;

    h = f + g;  // f = 5.85
    i = f - g;  // g = 0.43
    j = f * g;  // f = 8.15
    k = f / g;  // f = 1.16

    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;
    std::cout << "j: " << j << std::endl;
    std::cout << "k: " << k << std::endl;
  }

  // Testing:
  // 1. Comparison operators (>, <, >=, <=, ==, !=)
  {
    Fixed l(3.14f);
    Fixed m(2.71f);
    Fixed n(3.14f);

    std::cout << std::boolalpha;
    std::cout << "l > m: " << (l > m) << std::endl;
    std::cout << "l < m: " << (l < m) << std::endl;
    std::cout << "l >= m: " << (l >= m) << std::endl;
    std::cout << "l <= m: " << (l <= m) << std::endl;
    std::cout << "l == m: " << (l == m) << std::endl;
    std::cout << "l != m: " << (l != m) << std::endl;
    std::cout << "l == n: " << (l == n) << std::endl;
    std::cout << std::noboolalpha;
  }

  // Testing:
  // 1. Increment and decrement operators (++, --)
  // 2. Static methods (min, max)
  {
    Fixed o;
    Fixed const p( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << o << std::endl;
    std::cout << ++o << std::endl;
    std::cout << o << std::endl;
    std::cout << o++ << std::endl;
    std::cout << o << std::endl;
    std::cout << p << std::endl;
    std::cout << Fixed::max( o, p ) << std::endl;
    std::cout << Fixed::min( o, p ) << std::endl;
  }

  return EXIT_SUCCESS;
}
