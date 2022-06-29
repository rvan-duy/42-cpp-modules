#include <cstdlib>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void leaks() { system("leaks -q interface_and_recap"); };

int  main(void) {
   atexit(leaks);

   {
      Character * hero = new Character("Ruben");

      delete hero;
   }

   return EXIT_SUCCESS;
};
