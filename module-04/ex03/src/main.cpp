#include <cstdlib>

void leaks() { system("leaks -q interface_and_recap"); };

int  main(void) {
   atexit(leaks);

   return EXIT_SUCCESS;
}