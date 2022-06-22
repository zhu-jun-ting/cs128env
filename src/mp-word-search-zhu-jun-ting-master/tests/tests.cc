// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>
#include <string>

#include "CharPositions.hpp"
#include "WordLocation.hpp"
#include "WordSearchSolver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("hor and vertical", "[hv]") {
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'}};
  WordSearchSolver wss(puzzle);
	
	SECTION("correct search for hello as horizontal"){
		WordLocation wl = wss.FindWord("hello", CheckDirection::kHorizontal);
		REQUIRE(wl.word == "hello");
		REQUIRE(wl.char_positions[0].row == 1);
		REQUIRE(wl.char_positions[0].col == 0);
		REQUIRE(wl.char_positions[1].row == 1);
		REQUIRE(wl.char_positions[1].col == 1);
	}

	SECTION("no match for horizontal"){
		WordLocation wl = wss.FindWord("hallo", CheckDirection::kHorizontal);
		REQUIRE(wl.word.empty());
	}

	SECTION("no match for vertical"){
		WordLocation wl = wss.FindWord("hhhhh", CheckDirection::kVertical);
		REQUIRE(wl.word.empty());
	}

	SECTION("correct search for vertical") {
		WordLocation wl = wss.FindWord("muu", CheckDirection::kVertical);
		REQUIRE(wl.word == "muu");
		REQUIRE(wl.char_positions[0].row == 2);
		REQUIRE(wl.char_positions[0].col == 4);
		REQUIRE(wl.char_positions[1].row == 3);
		REQUIRE(wl.char_positions[1].col == 4);
	}

}

TEST_CASE("diagnal", "[dia]") {
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'}};
  WordSearchSolver wss(puzzle);

	SECTION("correct search for rightDiag") {
		WordLocation wl = wss.FindWord("alm", CheckDirection::kRightDiag);
		REQUIRE(wl.word == "alm");
		REQUIRE(wl.char_positions[0].row == 0);
		REQUIRE(wl.char_positions[0].col == 2);
		REQUIRE(wl.char_positions[1].row == 1);
		REQUIRE(wl.char_positions[1].col == 3);
	}	

	SECTION("no match for leftdiag"){
		WordLocation wl = wss.FindWord("uuuuu", CheckDirection::kLeftDiag);
		REQUIRE(wl.word.empty());
	}

	SECTION("no match for rightdiag"){
		WordLocation wl = wss.FindWord("hhhhh", CheckDirection::kRightDiag);
		REQUIRE(wl.word.empty());
	}

	SECTION("correct search for leftDiag") {
		WordLocation wl = wss.FindWord("aec", CheckDirection::kLeftDiag);
		REQUIRE(wl.word == "aec");
		REQUIRE(wl.char_positions[0].row == 0);
		REQUIRE(wl.char_positions[0].col == 2);
		REQUIRE(wl.char_positions[1].row == 1);
		REQUIRE(wl.char_positions[1].col == 1);
	}

}

TEST_CASE("general check", "[general]") {
  std::vector<std::vector<char>> puzzle{{'d', 'e', 'a', 'o', 'u'},
                                        {'h', 'e', 'l', 'l', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'e', 't', 'a', 'u'},
                                        {'t', 'e', 't', 'o', 'u'}};
  WordSearchSolver wss(puzzle);

	SECTION("have a match") {
		WordLocation wl = wss.FindWord("calom");
		REQUIRE(wl.word == "calom");
		REQUIRE(wl.char_positions[0].row == 2);
		REQUIRE(wl.char_positions[0].col == 0);
	}	

	SECTION("have no match") {
		WordLocation wl = wss.FindWord("thsud");
		REQUIRE(wl.word.empty());
	}	

}
