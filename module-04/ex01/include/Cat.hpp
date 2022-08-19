#ifndef MODULE_04_CAT_HPP
#define MODULE_04_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat();                           // Default constructor
  ~Cat();                          // Destructor
  Cat(const Cat &cat);             // Copy Constructor
  Cat &operator=(const Cat &cat);  // Copy assignment operator

  // Getters
  Brain *getBrainPtr() const;

  // Methods
  void makeSound() const;

 private:
  Brain *brain;
};

#endif  // MODULE_04_CAT_HPP
