// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Michael R. Nowak                Environment : ubuntu:latest               //
//  Date ......: 2022/02/07                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "board.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
constexpr int kBoardWidth = 7;
constexpr int kBoardHeight = 6;

bool AreEqual(DiskType solution[][kBoardWidth],
              DiskType student[][kBoardWidth]) {
  for (int i = 0; i < kBoardHeight; ++i) {
    for (int j = 0; j < kBoardWidth; ++j) {
      if (solution[i][j] != student[i][j]) return false;
    }
  }
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Board initialization", "[board_init]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(AreEqual(solution, student.board));
}

/////////////////////////////////////////////////////////////////////////////////////////////
TEST_CASE("test DropDiskToBoard", "[drop]") {
  Board b;
  SECTION("should drop a disk on a col") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    REQUIRE(b.board[0][0] == DiskType::kPlayer1);
  }
  SECTION("should drop two disks on one col") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    REQUIRE(b.board[0][0] == DiskType::kPlayer1);
    REQUIRE(b.board[1][0] == DiskType::kPlayer1);
  }
  SECTION("should drop two disk on different cols") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);
    REQUIRE(b.board[0][0] == DiskType::kPlayer1);
    REQUIRE(b.board[0][1] == DiskType::kPlayer1);
  }
  SECTION("should not drop disk on a full col") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    REQUIRE_THROWS_AS(DropDiskToBoard(b, DiskType::kPlayer1, 0), std::runtime_error);
  }
  SECTION("should not drop disk on a not valid col -1 and 8") {
    InitBoard(b);
    REQUIRE_THROWS_AS(DropDiskToBoard(b, DiskType::kPlayer1, -1), std::runtime_error);
    REQUIRE_THROWS_AS(DropDiskToBoard(b, DiskType::kPlayer1, 8), std::runtime_error);
  }
}

TEST_CASE("test winning for player2", "[kPlayer2]") {
  Board b;
  SECTION("should check a player2 winner") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer2, 0);
    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    DropDiskToBoard(b, DiskType::kPlayer2, 2);
    DropDiskToBoard(b, DiskType::kPlayer2, 3);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kLeftDiag));
  }
}

TEST_CASE("test SearchForWinner and CheckForWinner if have a winner", "[search&check]") {
  Board b;
  SECTION("should check a horizontal winner") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);
    DropDiskToBoard(b, DiskType::kPlayer1, 2);
    DropDiskToBoard(b, DiskType::kPlayer1, 3);
    REQUIRE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check a vertical winner") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    REQUIRE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check a right diagnal winner") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);

    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);

    DropDiskToBoard(b, DiskType::kPlayer2, 2);
    DropDiskToBoard(b, DiskType::kPlayer2, 2);
    DropDiskToBoard(b, DiskType::kPlayer1, 2);

    DropDiskToBoard(b, DiskType::kPlayer2, 3);
    DropDiskToBoard(b, DiskType::kPlayer2, 3);
    DropDiskToBoard(b, DiskType::kPlayer2, 3);
    DropDiskToBoard(b, DiskType::kPlayer1, 3);
    REQUIRE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check a left diagnal winner") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer2, 0);
    DropDiskToBoard(b, DiskType::kPlayer2, 0);
    DropDiskToBoard(b, DiskType::kPlayer2, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);

    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);

    DropDiskToBoard(b, DiskType::kPlayer2, 2);
    DropDiskToBoard(b, DiskType::kPlayer1, 2);
    
    DropDiskToBoard(b, DiskType::kPlayer1, 3);
    REQUIRE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check for no winner") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 3);
    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));

    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));

    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer2, WinningDirection::kLeftDiag));
  }
}

TEST_CASE("should check for no winner for 3-in-a-row") {
  Board b;
  SECTION("should check no horizontal winner for 3-in-a-row") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);
    DropDiskToBoard(b, DiskType::kPlayer1, 2);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check no horizontal winner for 2-in-a-row") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check no horizontal winner for 1-in-a-row") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }

  SECTION("should check no vertical winner for 3-in-a-row") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check no right diagnal winner for 3-") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer1, 0);

    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);

    DropDiskToBoard(b, DiskType::kPlayer2, 2);
    DropDiskToBoard(b, DiskType::kPlayer2, 2);
    DropDiskToBoard(b, DiskType::kPlayer1, 2);

    DropDiskToBoard(b, DiskType::kPlayer2, 3);
    DropDiskToBoard(b, DiskType::kPlayer2, 3);
    DropDiskToBoard(b, DiskType::kPlayer2, 3);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
  SECTION("should check no left diagnal winner for 3-") {
    InitBoard(b);
    DropDiskToBoard(b, DiskType::kPlayer2, 0);
    DropDiskToBoard(b, DiskType::kPlayer2, 0);
    DropDiskToBoard(b, DiskType::kPlayer2, 0);

    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    DropDiskToBoard(b, DiskType::kPlayer2, 1);
    DropDiskToBoard(b, DiskType::kPlayer1, 1);

    DropDiskToBoard(b, DiskType::kPlayer2, 2);
    DropDiskToBoard(b, DiskType::kPlayer1, 2);
    
    DropDiskToBoard(b, DiskType::kPlayer1, 3);
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer1));
    REQUIRE_FALSE(CheckForWinner(b, DiskType::kPlayer2));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kHorizontal));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kVertical));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kRightDiag));
    REQUIRE_FALSE(SearchForWinner(b, DiskType::kPlayer1, WinningDirection::kLeftDiag));
  }
}

TEST_CASE("test BoardLocationInBounds", "[location]") {
  SECTION("should a good location return true") {
    REQUIRE(BoardLocationInBounds(2, 2));
    REQUIRE(BoardLocationInBounds(0, 6));
    REQUIRE(BoardLocationInBounds(5, 0));
  }
  SECTION("should a negative location return false") {
    REQUIRE_FALSE(BoardLocationInBounds(-1, 2));
    REQUIRE_FALSE(BoardLocationInBounds(2, -4));
    REQUIRE_FALSE(BoardLocationInBounds(-2, -4));
  }
  SECTION("should a out-of-bound location return false") {
    REQUIRE_FALSE(BoardLocationInBounds(98, 2));
    REQUIRE_FALSE(BoardLocationInBounds(2, 89));
    REQUIRE_FALSE(BoardLocationInBounds(76, 980));
  }
}