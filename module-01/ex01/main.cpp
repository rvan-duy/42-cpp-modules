#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

Zombie *zombieHorde(int N, std::string name);

void leaks()
{
	system("leaks -q zombie");
}

int main (void) {
	atexit(leaks);

	Zombie *zombies = zombieHorde(10, "Bob");
	delete[] zombies;

	return EXIT_SUCCESS;
}
