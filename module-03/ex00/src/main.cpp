#include "ClapTrap.hpp"

#include <cstdlib>

int main(void)
{
    {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Testing ClapTrap Class with 10 attacks" << std::endl;
        std::cout << "--------------------------------------" << std::endl;

        ClapTrap HeroClapTrap("HeroClapTrap");
        ClapTrap Bandit("Bandit");

        std::cout << HeroClapTrap << std::endl;
        std::cout << Bandit << std::endl;

        for (int i = 0; i < 10; i++)
        {
            HeroClapTrap.attack("Bandit");
            Bandit.takeDamage(HeroClapTrap.getAttackDamage());
        }

        std::cout << HeroClapTrap << std::endl;
        std::cout << Bandit << std::endl;
    }

    {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Testing ClapTrap Class with 11 attacks" << std::endl;
        std::cout << "--------------------------------------" << std::endl;

        ClapTrap HeroClapTrap("HeroClapTrap");
        ClapTrap Bandit("Bandit");

        std::cout << HeroClapTrap << std::endl;
        std::cout << Bandit << std::endl;

        for (int i = 0; i < 11; i++)
        {
            HeroClapTrap.attack("Bandit");
            Bandit.takeDamage(HeroClapTrap.getAttackDamage());
        }

        std::cout << HeroClapTrap << std::endl;
        std::cout << Bandit << std::endl;
    }
    return EXIT_SUCCESS;
}