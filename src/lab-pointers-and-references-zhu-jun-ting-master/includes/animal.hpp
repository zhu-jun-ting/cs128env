#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

using std::string;

struct Animal {
  // Default constructor
  Animal() = default;

  // Parametrized constructor
  //
  // @param animal_name the name of the animal
  // @param animal_age the age of the animal
  // @param animal_food the food capacity or diet of the animal
  // @param animal_weight the weight of the animal
  // @param animal_habitat pointer to the habitat of the animal
  Animal(string animal_name,
         int animal_age,
         int animal_food,
         int animal_weight,
         int* animal_habitat) {
    name = animal_name;
    age = animal_age;
    food = animal_food;
    weight = animal_weight;
    habitat = animal_habitat;
  }

  string name;
  int age;
  int food;
  int weight;
  int* habitat;
};

#endif