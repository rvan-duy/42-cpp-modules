#ifndef MODULE_04_DOG_HPP
#define MODULE_04_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
  Dog();                           // Default constructor
  ~Dog();                          // Destructor
  Dog(const Dog &dog);             // Copy Constructor
  Dog &operator=(const Dog &dog);  // Copy assignment operator

  // Methods
  void makeSound() const;

 private:
  Brain *brain;
};

#endif  // MODULE_04_DOG_HPP
