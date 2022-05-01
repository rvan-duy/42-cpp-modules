#ifndef MODULE_00_ZOMBIE_HPP
#define MODULE_00_ZOMBIE_HPP

#include <string>

class Zombie {
    

    public:

        // Constructor
        Zombie(const std::string name);

        // Destructor
        ~Zombie();

        // Methods
        void    announce(void);
        Zombie *newZombie(std::string name);
        void    randomChump(std::string name);


    private:

        // Attributes
        std::string _name;  // Name of the zombie

};

#endif // MODULE_00_ZOMBIE_HPP
