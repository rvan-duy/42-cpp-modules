#ifndef MODULE_04_WRONGCAT_HPP
#define MODULE_04_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();                                // Default constructor
  ~WrongCat();                               // Destructor
  WrongCat(const WrongCat &cat);             // Copy Constructor
  WrongCat &operator=(const WrongCat &cat);  // Copy assignment operator

  // Methods
  void makeSound() const;
};

#endif  // MODULE_04_WRONGCAT_HPP
