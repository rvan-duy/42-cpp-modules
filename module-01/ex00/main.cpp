#include "Zombie.hpp"
#include <cstdlib>

int main (void) {
    Zombie handler("Handler");

    // Create a new zombie on the heap
    Zombie *new_zombie_ptr = handler.newZombie("Heap");
    new_zombie_ptr->announce();
    delete(new_zombie_ptr);

    // Create a new zombie on the stack
    handler.randomChump("Stack");

    return EXIT_SUCCESS;
}
