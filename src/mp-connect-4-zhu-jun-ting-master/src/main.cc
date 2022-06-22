#include <iostream>

#include "board.hpp"

int main() {
  Board b;
  InitBoard(b);
  DropDiskToBoard(b, DiskType::kPlayer1, 1);

  std::cout << BoardToStr(b) << std::endl;
}