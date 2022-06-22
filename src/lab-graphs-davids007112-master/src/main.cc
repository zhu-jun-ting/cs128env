#include <iostream>
#include <utility>
#include <vector>

#include "solution.hpp"

int main() {
  // std::vector<std::pair<std::string, std::string>> cs_classes(
  //     {{"CS 124", "CS 128"},
  //      {"CS 128", "CS 225"},
  //      {"CS 225", "CS 233"},
  //      {"CS 233", "CS 241"},
  //      {"CS 225", "CS 241"}});
  // std::vector<std::pair<std::string, std::string>> psyc_classes(
  //     {{"PSYC 100", "PSYC 210"},
  //      {"PSYC 100", "PSYC 238"},
  //      {"PSYC 210", "PSYC 311"},
  //      {"PSYC 210", "PSYC 413"},
  //      {"PSYC 100", "PSYC 216"},
  //      {"PSYC 216", "PSYC 465"}});
  // Solution cs(cs_classes);
  // Solution psyc(psyc_classes);

  // you can print out the contents of your Solution's adjacency list if you
  // like, e.g. std::cout << cs << std::endl;
  
  // one example call to Solve() would be cs.Solve("CS 125", "CS 225");
  // This should be 2 because when starting from "CS 125" you need to take
  // "CS 124" and "CS 128" before taking "CS 225"

  // std::cout << "Number of classes needed before CS 225 starting at CS 125 : "
  //           << cs.Solve("CS 124", "CS 225") << std::endl;
  // std::cout
  //     << "Number of classes needed before PSYC 413 starting at PSYC 100 : "
  //     << psyc.Solve("PSYC 100", "PSYC 413") << std::endl;
  // std::cout
  //     << "Number of classes needed before PSYC 238 starting at PSYC 100 : "
  //     << psyc.Solve("PSYC 100", "PSYC 238") << std::endl;

  /*   while this case doesn't make sense in the context of satisfying
    prerequisites, it ensures you are finding the SHORTEST path and not just A
    path. Output should be 1 */

  // std::cout << "Number of classes needed before CS 241 starting at CS 225 : "
  //           << cs.Solve("CS 225", "CS 233") << std::endl;
}
