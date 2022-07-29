#ifndef MODULE_04_AMATERIA_HPP
#define MODULE_04_AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria {
 public:
  AMateria();                                    // Default constructor
  AMateria(std::string const& type);             // Constructor with type
  virtual ~AMateria();                           // Destructor
  AMateria(const AMateria& materia);             // Copy constructor
  AMateria& operator=(const AMateria& materia);  // Copy assignment operator

  // Getters
  std::string const& getType() const;

  // Methods
  virtual AMateria* clone() const = 0;
  virtual void      use(ICharacter& target);

 protected:
  std::string type;
};

#endif  // MODULE_04_AMATERIA_HPP
