#ifndef MODULE_04_MATERIASOURCE_HPP
#define MODULE_04_MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();                                        // Default constructor
  ~MateriaSource();                                       // Destructor
  MateriaSource(const MateriaSource& source);             // Copy constructor
  MateriaSource& operator=(const MateriaSource& source);  // Copy assignment operator

  // Methods
  void      learnMateria(AMateria* m);
  AMateria* createMateria(std::string const& type);

 private:
  const static int inventory_limit = 4;
  AMateria**       inventory;
};

#endif  // MODULE_04_MATERIASOURCE_HPP
