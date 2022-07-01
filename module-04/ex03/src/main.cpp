#include <cstdlib>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void leaks() { system("leaks -q interface_and_recap"); };

int  main(void) {
   atexit(leaks);

   {
      Character * hero = new Character("Ruben");

      AMateria * ice = new Ice();
      AMateria * cure = new Cure();

      ice->use(*hero);
      cure->use(*hero);

      delete ice;
      delete cure;
      delete hero;
   }

   return EXIT_SUCCESS;
};
