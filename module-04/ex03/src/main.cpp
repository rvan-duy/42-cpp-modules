#include <cstdlib>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// void leaks() { system("leaks -q interface_and_recap"); };

// int  main(void) {
//    atexit(leaks);

//    {
//       Character * hero = new Character("Ruben");

//       AMateria * ice = new Ice();
//       AMateria * cure = new Cure();

//       ice->use(*hero);
//       cure->use(*hero);

//       delete ice;
//       delete cure;
//       delete hero;
//    }

//    return EXIT_SUCCESS;
// };

int main() {
  IMateriaSource* src = new MateriaSource();

  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria*   tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");
  
  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  return 0;
}
