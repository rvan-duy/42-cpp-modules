#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "catch.hpp"

SCENARIO("Initializing Animal class and testing methods", "[Animal Class]") {
  GIVEN("Animal Class") {
    WHEN("Animal Class is an Animal") {
      Animal* animal = new Animal();
      THEN("Animal type is empty") { REQUIRE(animal->getType() == ""); }
      delete animal;
    }
    WHEN("Animal Class is a Dog") {
      Animal* dog = new Dog();
      THEN("Animal type is Dog") { REQUIRE(dog->getType() == "Dog"); }
      delete dog;
    }
    WHEN("Animal Class is a Cat") {
      Animal* cat = new Cat();
      THEN("Animal type is Cat") { REQUIRE(cat->getType() == "Cat"); }
      delete cat;
    }
  }
  GIVEN("Dog Class (Derived from Animal)") {
    WHEN("Dog Class is an Animal") {
      Dog* dog = new Dog();
      THEN("Dog Type is a Dog") { REQUIRE(dog->getType() == "Dog"); }
      delete dog;
    }
  }
  GIVEN("Cat Class (Derived from Animal)") {
    WHEN("Cat Class is an Animal") {
      Cat* cat = new Cat();
      THEN("Cat Type is a Dog") { REQUIRE(cat->getType() == "Cat"); }
      delete cat;
    }
  }
}
