#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include <vector>

#include "animal.hpp"

using std::string;
using std::vector;

class Zoo {
public:
  // Default constructor. animals_ should be initialized to an empty vector.
  Zoo() = default;

  // Parametrized constructor.
  //
  // @param animals vector of animal pointers to initialize the zoo with
  Zoo(const vector<Animal*>& animals);

  // Adds an animal to the list of animals in the zoo.
  // Checks whether the animal's name is valid, and if not, changes it to be
  // valid. Valid names only have alphabetical characters.
  //
  // @param animal pointer to the animal to be added to the zoo
  void AddAnimal(Animal* animal);

  // Changes an animals diet (food capacity).
  //
  // @param animal reference to the animal whose diet is being changed
  // @param food pointer to the new food capacity of the animal
  void ChangeDiet(Animal& animal, int* food);

  // Overloaded function. Changes the habitat of an animal in the zoo.
  // This function should take a pointer to an Animal object and change its
  // habitat.
  //
  // @param animal pointer to the animal whose habitat is being changed
  // @param habitat the new habitat
  void ChangeHabitat(const Animal* animal, int habitat);

  // Overloaded function. Changes the habitat of an animal in the zoo.
  // This function should take a reference to an Animal object and change its
  // habitat.
  //
  // @param animal reference to the animal whose habitat is being changed
  // @param habitat the new habitat
  void ChangeHabitat(Animal animal, int habitat);

  // Checks whether two habitats are the same.
  //
  // @param h1 pointer to the first habitat
  // @param h2 pointer to the second habitat
  // @return true if the two pointers point to the same habitat, false otherwise
  bool IsSameHabitat(const int* h1, const int* h2);

  // Removes an animal from the list of animals in the zoo.
  // std::vector::erase() might be of help.
  //
  // @param animal pointer to the animal to be removed
  void RemoveAnimal(Animal* animal);

  // Getter for the list of animals in the zoo.
  //
  // @return the vector containing the list of animals in the zoo
  vector<Animal*> GetAnimals();

  // Prints the details of all animals in the zoo
  void PrintAnimals();

private:
  // Checks whether the name of the animal is valid.
  // Valid names only have alphabetical characters.
  //
  // @param animal const reference to the animal whose name is being checked
  // @return true if the name is valid, false otherwise
  bool IsValidName(const Animal& animal);

  // Changes the name of an animal to be valid.
  //
  // @param animal reference to the animal whose name is being changed
  void ChangeAnimalName(Animal& animal);

  // List of all the animals in the zoo.
  vector<Animal*> animals_;
};

#endif
