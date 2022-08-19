#ifndef MODULE_04_WRONGANIMAL_HPP
#define MODULE_04_WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
 public:
  WrongAnimal();                                      // Default constructor
  virtual ~WrongAnimal();                             // Destructor
  WrongAnimal(const WrongAnimal &animal);             // Copy Constructor
  WrongAnimal &operator=(const WrongAnimal &animal);  // Copy assignment operator

  // Getters
  const std::string &getType() const;

  // Methods
  void makeSound() const;

 protected:
  std::string type;
};

#endif  // MODULE_04_WRONGANIMAL_HPP
