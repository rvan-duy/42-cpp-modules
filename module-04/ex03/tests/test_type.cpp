#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "catch.hpp"

SCENARIO("Initializing Character + AMateria classes and testing methods", "[Classes Functionality]") {
  GIVEN("Character Class") {
    WHEN("Character Class has no name") {
      Character* hero = new Character();
      THEN("Character name is empty") { REQUIRE(hero->getName() == ""); }
      delete hero;
    }
    WHEN("Character Class has a name") {
      Character* hero = new Character("Hero");
      THEN("Character name is empty") { REQUIRE(hero->getName() == "Hero"); }
      delete hero;
    }
    WHEN("Character Class is adding 4 items to its inventory") {
      Character* hero   = new Character("Hero");
      AMateria*  item_1 = new Ice();
      AMateria*  item_2 = new Ice();
      AMateria*  item_3 = new Cure();
      AMateria*  item_4 = new Cure();
      hero->equip(item_1);
      hero->equip(item_2);
      hero->equip(item_3);
      hero->equip(item_4);
      THEN("Index 0 is equal to item_1") { REQUIRE(hero->getItem(0) == item_1); }
      THEN("Index 1 is equal to item_2") { REQUIRE(hero->getItem(1) == item_2); }
      THEN("Index 2 is equal to item_3") { REQUIRE(hero->getItem(2) == item_3); }
      THEN("Index 3 is equal to item_4") { REQUIRE(hero->getItem(3) == item_4); }
      hero->unequip(0);
      hero->unequip(1);
      hero->unequip(2);
      hero->unequip(3);
      THEN("Index 0 is equal to NULL") { REQUIRE(hero->getItem(0) == NULL); }
      THEN("Index 1 is equal to NULL") { REQUIRE(hero->getItem(1) == NULL); }
      THEN("Index 2 is equal to NULL") { REQUIRE(hero->getItem(2) == NULL); }
      THEN("Index 3 is equal to NULL") { REQUIRE(hero->getItem(3) == NULL); }
      delete item_1;
      delete item_2;
      delete item_3;
      delete item_4;
      delete hero;
    }
    WHEN("Character Class is adding 6 items to its inventory") {
      Character* hero   = new Character("Hero");
      AMateria*  item_1 = new Ice();
      AMateria*  item_2 = new Ice();
      AMateria*  item_3 = new Cure();
      AMateria*  item_4 = new Cure();
      AMateria*  item_5 = new Ice();
      AMateria*  item_6 = new Cure();
      hero->equip(item_1);
      hero->equip(item_2);
      hero->equip(item_3);
      hero->equip(item_4);
      hero->equip(item_5);
      hero->equip(item_6);
      THEN("Index 0 is equal to item_1") { REQUIRE(hero->getItem(0) == item_1); }
      THEN("Index 1 is equal to item_2") { REQUIRE(hero->getItem(1) == item_2); }
      THEN("Index 2 is equal to item_3") { REQUIRE(hero->getItem(2) == item_3); }
      THEN("Index 3 is equal to item_4") { REQUIRE(hero->getItem(3) == item_4); }
      hero->unequip(0);
      hero->unequip(1);
      hero->unequip(2);
      hero->unequip(3);
      hero->unequip(4);   // shouldn't crash
      hero->unequip(5);   // shouldn't crash
      hero->unequip(-1);  // shouldn't crash
      hero->equip(item_5);
      hero->equip(item_6);
      THEN("Index 0 is equal to item_5") { REQUIRE(hero->getItem(0) == item_5); }
      THEN("Index 1 is equal to item_6") { REQUIRE(hero->getItem(1) == item_6); }
      THEN("Index 2 is equal to NULL") { REQUIRE(hero->getItem(2) == NULL); }
      THEN("Index 3 is equal to NULL") { REQUIRE(hero->getItem(3) == NULL); }
      hero->unequip(0);
      hero->unequip(1);
      hero->unequip(2);
      hero->unequip(3);
      THEN("Index 0 is equal to NULL") { REQUIRE(hero->getItem(0) == NULL); }
      THEN("Index 1 is equal to NULL") { REQUIRE(hero->getItem(1) == NULL); }
      THEN("Index 2 is equal to NULL") { REQUIRE(hero->getItem(2) == NULL); }
      THEN("Index 3 is equal to NULL") { REQUIRE(hero->getItem(3) == NULL); }
      delete item_1;
      delete item_2;
      delete item_3;
      delete item_4;
      delete item_5;
      delete item_6;
      delete hero;
    }
    WHEN("Character Class is copied") {
      Character hero("Hero");
      AMateria* item_1 = new Ice();
      AMateria* item_2 = new Cure();
      hero.equip(item_1);
      hero.equip(item_2);
      Character copied_hero;
      copied_hero = hero;
      THEN("The inventory of the character is deep copied") {
        REQUIRE(&hero != &copied_hero);
        REQUIRE(hero.getItem(0) != copied_hero.getItem(0));
        REQUIRE(hero.getItem(1) != copied_hero.getItem(1));
      }
    }
    WHEN("Character Class is copied and overwritten") {
      Character hero("Hero");
      Character villain("Villain");
      AMateria* item_1 = new Ice();
      AMateria* item_2 = new Cure();
      AMateria* item_3 = new Cure();
      AMateria* item_4 = new Ice();
      hero.equip(item_1);
      hero.equip(item_2);
      villain.equip(item_3);
      villain.equip(item_4);
      villain = hero;
      THEN("The inventory of the character is deep copied") {
        REQUIRE(&hero != &villain);
        REQUIRE(hero.getItem(0) != villain.getItem(0));
        REQUIRE(hero.getItem(1) != villain.getItem(1));
      }
    }
  }
  GIVEN("Ice Class") {
    WHEN("Ice Class is initialized") {
      AMateria* ice = new Ice();
      THEN("ice type is ice") { REQUIRE(ice->getType() == "ice"); }
      delete ice;
    }
    WHEN("Ice Class is cloned") {
      AMateria* ice        = new Ice();
      AMateria* cloned_ice = ice->clone();
      THEN("cloned_ice is not NULL") { REQUIRE(cloned_ice != NULL); }
      THEN("ice is not the same address as cloned_ice") { REQUIRE(ice != cloned_ice); }
      THEN("cloned_ice type is ice") { REQUIRE(cloned_ice->getType() == "ice"); }
      delete ice;
      delete cloned_ice;
    }
  }
  GIVEN("Cure Class") {
    WHEN("Cure Class is initialized") {
      AMateria* cure = new Cure();
      THEN("cure type is cure") { REQUIRE(cure->getType() == "cure"); }
      delete cure;
    }
    WHEN("Cure Class is cloned") {
      AMateria* cure        = new Cure();
      AMateria* cloned_cure = cure->clone();
      THEN("cloned_cure is not NULL") { REQUIRE(cloned_cure != NULL); }
      THEN("cure is not the same address as cloned_cure") { REQUIRE(cure != cloned_cure); }
      THEN("cloned_cure type is cure") { REQUIRE(cloned_cure->getType() == "cure"); }
      delete cure;
      delete cloned_cure;
    }
  }
}
