#ifndef MODULE_04_IMATERIASOURCE_HPP
#define MODULE_04_IMATERIASOURCE_HPP

#include <string>

#include "AMateria.hpp"

class AMateria; // Forward declaration, needed in order to compile

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}
  virtual void      learnMateria(AMateria*)                = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif  // MODULE_04_IMATERIASOURCE_HPP
