#ifndef MODULE_04_ICE_HPP
#define MODULE_04_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice();                           // Default constructor
  virtual ~Ice();                  // Destructor
  Ice(const Ice &ice);             // Copy constructor
  Ice &operator=(const Ice &ice);  // Copy assignment operator

  // Methods
  Ice *clone() const;
  void use(ICharacter &target);
};

#endif  // MODULE_04_ICE_HPP
