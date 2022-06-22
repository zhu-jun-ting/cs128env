#include <iostream>
#include <string>
#include <fstream>

#include "functions.hpp"
#include "utilities.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
              << std::endl;
    return 1;
  }

  string name = GetName(argv[1], argv[2]);
  std::cout << name << std::endl;

  return 0;
}