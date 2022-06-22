#include <algorithm>

#include "zoo.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  Zoo zoo;
  int habitats[] = {1, 2, 3};
  int* h1 = &habitats[0];
  int* h2 = &habitats[1];
  int* h3 = &habitats[2];

  Animal panda("PeculiarPanda", 12, 50, 300, h1);
  Animal seal("SmartSeal", 7, 20, 200, h2);
  Animal badger("Breezy Badger", 4, 5, 50, h3);

  zoo.AddAnimal(&panda);
  zoo.AddAnimal(&seal);
  zoo.AddAnimal(&badger);

  int new_panda_food = 75;
  zoo.ChangeDiet(panda, &new_panda_food);
  if (panda.food == 75 && panda.weight == 325) {
    cout << "Successfully changed panda's diet!" << endl;
  } else {
    cout << "Could not change panda's diet!" << endl;
  }

  zoo.ChangeHabitat(&badger, *h1);
  if (*badger.habitat == *h1) {
    cout << "Successfully changed badger's habitat!" << endl;
  } else {
    cout << "Could not change badger's habitat!" << endl;
  }

  zoo.ChangeHabitat(seal, *h3);
  if (*seal.habitat == *h3) {
    cout << "Successfully changed seal's habitat!" << endl;
  } else {
    cout << "Could not change seal's habitat!" << endl;
  }

  if (zoo.IsSameHabitat(badger.habitat, h1)) {
    cout << "The panda and the badger are in the same habitat!" << endl;
  } else {
    cout << "The panda and the badger are in different habitats!" << endl;
  }

  zoo.RemoveAnimal(&panda);
  vector<Animal*> animals = zoo.GetAnimals();
  if (std::count(animals.begin(), animals.end(), &panda) == 0) {
    cout << "Successfully removed panda from the zoo!" << endl;
  } else {
    cout << "Failed to remove panda from the zoo!" << endl;
  }

  return 0;
}