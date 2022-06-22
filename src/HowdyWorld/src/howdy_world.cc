#include <iostream>

#include "utilities.hpp"

int main(int argc, char* argv[]) {
  for (int i = 1; i < argc; ++i) {
    std::cout << "Howdy, " << argv[i] << std::endl;
  }
  std::cout << Howdy("Michael") << std::endl;
}