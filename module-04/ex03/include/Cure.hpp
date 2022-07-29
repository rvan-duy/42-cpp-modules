#ifndef MODULE_04_CURE_HPP
#define MODULE_04_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure();                             // Default constructor
  virtual ~Cure();                    // Destructor
  Cure(const Cure &cure);             // Copy constructor
  Cure &operator=(const Cure &cure);  // Copy assignment operator

  // Methods
  Cure *clone() const;
  void  use(ICharacter &target);
};

#endif  // MODULE_04_CURE_HPP
