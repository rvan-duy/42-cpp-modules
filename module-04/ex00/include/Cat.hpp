#ifndef MODULE_04_CAT_HPP
#define MODULE_04_CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat();                           // Default constructor
  ~Cat();                          // Destructor
  Cat(const Cat &cat);             // Copy Constructor
  Cat &operator=(const Cat &cat);  // Copy assignment operator

  // Methods
  void makeSound() const;
};

#endif  // MODULE_04_CAT_HPP
