#ifndef MODULE_04_CHARACTER_HPP
#define MODULE_04_CHARACTER_HPP

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

class Character : public ICharacter {
 public:
  Character();                                       // Default constructor
  Character(const std::string& name);                // Constructor with name
  ~Character();                                      // Destructor
  Character(const Character& character);             // Copy constructor
  Character& operator=(const Character& character);  // Copy assignment operator

  // Getters
  std::string const& getName() const;         // Name of character
  AMateria*          getItem(int idx) const;  // Address of item on given index

  // Methods
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);

 private:
  std::string      name;
  const static int inventory_limit = 4;
  AMateria*        inventory[inventory_limit];
};

#endif  // MODULE_04_CHARACTER_HPP
