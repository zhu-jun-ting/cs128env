#include <iostream>
 
#include "roster.hpp" 
 
int main() {
  Roster r("Professor Nowak");
  r.AddStudent("Professor Amato");
  r.AddStudent("Professor Fleck");
  r.AddStudent("Professor Evans");

  for (auto const& student : r) {
    std::cout << student << std::endl;
  }

  return 0;
}
 
/*
Professor Amato
Professor Evans
Professor Fleck
Professor Nowak
*/
