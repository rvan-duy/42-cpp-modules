#include "Zombie.hpp"
#include <cstdlib>

int main (void) {

    Zombie zombie_object("Object");

    // Create a new zombie on the heap
    Zombie *new_zombie_ptr = zombie_object.newZombie("Heap");
    new_zombie_ptr->announce();
    delete(new_zombie_ptr);

    // Create a new zombie on the stack
    zombie_object.randomChump("Stack");

    return EXIT_SUCCESS;
}
