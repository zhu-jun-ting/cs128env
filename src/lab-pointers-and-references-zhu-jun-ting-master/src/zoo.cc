#include "zoo.hpp"

#include <cctype>

using std::cout;
using std::endl;
using std::string;

Zoo::Zoo(const vector<Animal*>& animals) { animals_ = animals; }

void Zoo::AddAnimal(Animal* animal) {
  if (!IsValidName(*animal)) {
    ChangeAnimalName(*animal);
  }
  if (IsValidName(*animal)) {
    animals_.push_back(animal);
    cout << "Successfully added " << animal->name << " " << endl;
  } else {
    cout << "Failed to add " << animal->name << " :(" << endl;
  }
}

void Zoo::ChangeDiet(Animal& animal, int* food) {
  animal.weight -= animal.food;
  animal.food = *food;
  animal.weight += animal.food;
}

void Zoo::ChangeHabitat(const Animal* animal, int habitat) {
  *animal->habitat = habitat;
}

void Zoo::ChangeHabitat(Animal animal, int habitat) {
  *animal.habitat = habitat;
}

bool Zoo::IsSameHabitat(const int* h1, const int* h2) { return (*h1 == *h2); }

void Zoo::RemoveAnimal(Animal* animal) {
  // TODO: Implement me!
  if (animal != nullptr) {
    if (!IsValidName(*animal)) {
      ChangeAnimalName(*animal);
    }
    if (IsValidName(*animal)) {
      for (unsigned i = 0; i < animals_.size(); i++ ) {
        if (animals_[i] == animal) {
          animals_.erase(animals_.begin() + i);
          cout << "Successfully removed " << animal->name << " " << endl;
          return;
        }
      }
      cout << "Failed to remove " << animal->name << " :(" << endl;
    } else {
      cout << "Failed to remove " << animal->name << " :(" << endl;
    }
  }
}

vector<Animal*> Zoo::GetAnimals() { return animals_; }

void Zoo::PrintAnimals() {
  for (unsigned i = 0; i < animals_.size(); ++i) {
    cout << "Name: " << animals_[i]->name << " ";
    cout << "Age: " << animals_[i]->age << " ";
    cout << "Food: " << animals_[i]->food << " ";
    cout << "Weight: " << animals_[i]->weight << " ";
    cout << "Habitat: " << animals_[i]->habitat << endl;
  }
}

bool Zoo::IsValidName(const Animal& animal) {
  for (unsigned i = 0; i < animal.name.size(); i++) {
    if (!static_cast<bool>(std::isalpha(animal.name[i]))) {
      return false;
    }
  }

  return true;
}

void Zoo::ChangeAnimalName(Animal& animal) {
  for (unsigned i = 0; i < animal.name.size(); i++) {
    if (!static_cast<bool>(std::isalpha(animal.name[i]))) {
      animal.name.erase(animal.name.begin() + i);
      --i;
    }
  }
}