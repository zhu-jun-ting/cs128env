#include <iostream>
#include <string>
#include <vector>

#include "WordSearchSolver.hpp"

int main() {
  // std::cout << "hello!";
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'}};
  WordSearchSolver wss(puzzle);
  std::cout << wss.FindWord("hello", CheckDirection::kHorizontal);
  std::cout << wss.FindWord("hello");
}