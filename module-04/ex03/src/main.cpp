#include <cstdlib>

#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "                Basic test              " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    IMateriaSource* src = new MateriaSource();

    Ice ice;
    Cure cure;

    src->learnMateria(&ice);
    src->learnMateria(&cure);

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

    system("/usr/bin/leaks -q interface_and_recap");
  }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "          Learning Ice 5 times          " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    IMateriaSource* src = new MateriaSource();

    AMateria * ices[5];
    for (int i = 0; i < 5; i++) {
      ices[i] = new Ice();
      src->learnMateria(ices[i]);
    }

    for (int i = 0; i < 5; i++) {
      delete ices[i];
    }
    delete src;

    system("/usr/bin/leaks -q interface_and_recap");
  }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Equipping and unequipping character class" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    IMateriaSource* src = new MateriaSource();

    Ice ice;
    Cure cure;

    src->learnMateria(&ice);
    src->learnMateria(&cure);

    ICharacter* me = new Character("me");

    AMateria*   tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->unequip(0);
    delete tmp;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->unequip(0);
    delete tmp;
    tmp = src->createMateria("randomMateria");

    me->unequip(3);
    me->unequip(7);

    delete src;
    delete me;

    system("/usr/bin/leaks -q interface_and_recap");
  }

  return EXIT_SUCCESS;
}
