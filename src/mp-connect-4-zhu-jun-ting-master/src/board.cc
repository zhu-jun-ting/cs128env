#include "board.hpp"

// you might need additional includes
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

/**************************************************************************/
/* your function definitions                                              */
/**************************************************************************/

void InitBoard(Board& b) {
  // below was minimal to get tests to actually compile and given test case to
  // fail
  for (int i = 0; i < Board::kBoardHeight; i++) {
    for (int j = 0; j < Board::kBoardWidth; j++) {
      b.board[i][j] = DiskType::kEmpty;
    }
  }
}

void DropDiskToBoard(Board& b, DiskType disk, int col) {
  if (!BoardLocationInBounds(0, col)) {
    throw std::runtime_error("column number out of range.");
  }
  for (int i = 0; i < Board::kBoardHeight; i++) {
    if (b.board[i][col] == DiskType::kEmpty) {
      b.board[i][col] = disk;
      return;
    }
  }
  throw std::runtime_error("this column is full.");
}

bool CheckForWinner(Board& b, DiskType disk) {
  return SearchForWinner(b, disk, WinningDirection::kHorizontal) ||
    SearchForWinner(b, disk, WinningDirection::kVertical) ||
    SearchForWinner(b, disk, WinningDirection::kRightDiag) ||
    SearchForWinner(b, disk, WinningDirection::kLeftDiag);
}

bool SearchForWinner(Board& b, DiskType disk, WinningDirection to_check) {
  if (to_check == WinningDirection::kHorizontal) {
    // check (i, j), (i, j+1), (i, j+2), (i, j+3)
    for (int i = 0; i < Board::kBoardHeight; i++) {
      for (int j = 0; j < Board::kBoardWidth - 3; j++) {
        if (CheckForSameDiskType(disk, b.board[i][j], b.board[i][j+1], b.board[i][j+2], b.board[i][j+3])) {
          return true;
        }
      }
    }
  } else if (to_check == WinningDirection::kVertical) {
    // check (i, j), (i+1, j), (i+2, j), (i+3, j)
    for (int i = 0; i < Board::kBoardHeight - 3; i++) {
      for (int j = 0; j < Board::kBoardWidth; j++) {
        if (CheckForSameDiskType(disk, b.board[i][j], b.board[i+1][j], b.board[i+2][j], b.board[i+3][j])) {
          return true;
        }
      }
    }
  } else if (to_check == WinningDirection::kRightDiag) {
    // check (i, j), (i+1, j+1), (i+2, j+2), (i+3, j+3)
    for (int i = 0; i < Board::kBoardHeight - 3; i++) {
      for (int j = 0; j < Board::kBoardWidth - 3; j++) {
        if (CheckForSameDiskType(disk, b.board[i][j], b.board[i+1][j+1], b.board[i+2][j+2], b.board[i+3][j+3])) {
          return true;
        }
      }
    }
  } else if (to_check == WinningDirection::kLeftDiag) {
    // check (i, j), (i+1, j-1), (i+2, j-2), (i+3, j-3)
    for (int i = 0; i < Board::kBoardHeight - 3; i++) {
      for (int j = 3; j < Board::kBoardWidth; j++) {
        if (CheckForSameDiskType(disk, b.board[i][j], b.board[i+1][j-1], b.board[i+2][j-2], b.board[i+3][j-3])) {
          return true;
        }
      }
    }
  }
  return false;
}

bool CheckForSameDiskType(DiskType disk_to_check, DiskType disk1, DiskType disk2, DiskType disk3, DiskType disk4) {
  return disk1 == disk_to_check && disk2 == disk_to_check && disk3 == disk_to_check && disk4 == disk_to_check;
}

bool BoardLocationInBounds(int row, int col) {
  return row >= 0 && col >= 0 && row < Board::kBoardHeight && col < Board::kBoardWidth;
}

/**************************************************************************/
/* provided to you                                                        */
/**************************************************************************/
std::string BoardToStr(const Board& b) {
  constexpr int kTotalWidth = Board::kBoardWidth * 11 - Board::kBoardHeight - 1;
  std::stringstream ss;
  ss << std::endl;
  for (int row = Board::kBoardHeight; row > 0; --row) {
    ss << " |";
    for (int col = 0; col < Board::kBoardWidth; ++col) {
      std::string value_here;
      value_here.push_back(static_cast<char>(b.board[row - 1][col]));
      ss << ' ' << CenterStr(value_here, Board::kBoardWidth + 1) << '|';
    }
    ss << std::endl;
    ss << " |" << std::setw(kTotalWidth) << std::setfill('-') << '|'
       << std::endl;
  }
  ss << " |";
  for (int col = 0; col < Board::kBoardWidth; ++col) {
    ss << ' ' << CenterStr(std::to_string(col), Board::kBoardWidth + 1) << '|';
  }
  return ss.str();
}

std::string CenterStr(const std::string& str, int col_width) {
  // quick and easy (but error-prone) implementation
  auto padl = (col_width - str.length()) / 2;
  auto padr = (col_width - str.length()) - padl;
  std::string strf = std::string(padl, ' ') + str + std::string(padr, ' ');
  return strf;
}