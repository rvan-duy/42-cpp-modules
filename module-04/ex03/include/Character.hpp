#ifndef MODULE_04_CHARACTER_HPP
#define MODULE_04_CHARACTER_HPP

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

// 1. Character has an inventory of 4 slots, max == 4 materias
// 2. Inventory is empty at construction
// 3. When an materia is equipped, they go into the first slot they can find
//      - order from 0 to 3
//      - if inventory is full, dont do anything
// 4. Use/unequip can be used to do something with a materia
//      - if it doesn't exist nothing should happen
//      - unequip() must NOT delete anything

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
