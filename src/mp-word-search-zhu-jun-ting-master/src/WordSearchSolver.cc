#include "WordLocation.hpp"
#include "CharPositions.hpp" 
#include "WordSearchSolver.hpp"
#include <cassert> 
#include <cctype> 
#include <cstddef> 
#include <iostream>
#include <string> 
#include <limits>
#include <vector>

bool WordSearchSolver::LocationInBounds(size_t row, size_t col) const {
  return ((row < puzzle_height_) && (col < puzzle_width_));
}

// enum class CheckDirection { kHorizontal, kVertical, kLeftDiag, kRightDiag };

// class WordSearchSolver {
// public:
//   WordSearchSolver(const std::vector<std::vector<char>>& puzzle);
//   WordLocation FindWord(const std::string& word);
//   WordLocation FindWord(const std::string& word, CheckDirection direction);

// private:
//   bool LocationInBounds(size_t row, size_t col) const;
//   std::vector<std::vector<char>> puzzle_;
//   size_t puzzle_height_;
//   size_t puzzle_width_;
// };

WordSearchSolver::WordSearchSolver(const std::vector<std::vector<char>>& puzzle): 
  puzzle_(puzzle), puzzle_height_(puzzle.size()), puzzle_width_(puzzle[0].size()) {
    
  }

WordLocation WordSearchSolver::FindWord(const std::string& word) {
  WordLocation wl_horizontal = FindWord(word, CheckDirection::kHorizontal);
  WordLocation wl_vertical = FindWord(word, CheckDirection::kVertical);
  WordLocation wl_ldiag = FindWord(word, CheckDirection::kLeftDiag);
  WordLocation wl_rdiag = FindWord(word, CheckDirection::kRightDiag);
  WordLocation to_return;
  if(wl_horizontal.word != WordLocation{}.word) {
    to_return = wl_horizontal;
  } else if(wl_rdiag.word != WordLocation{}.word) {
    to_return =  wl_rdiag;
  } else if(wl_ldiag.word != WordLocation{}.word) {
    to_return =  wl_ldiag;
  } else if(wl_vertical.word != WordLocation{}.word) {
    to_return = wl_vertical;
  } else {
    to_return = WordLocation{};
  }
  return to_return;
}

WordLocation WordSearchSolver::GetWordLocation(const std::string& word, const std::vector<char>& chars, size_t i, size_t j, CheckDirection direction) {
  WordLocation wl;
  if(direction == CheckDirection::kHorizontal) {
    wl.word = word;
    for(unsigned m = 0; m < chars.size(); m++) {
      CharPositions cp{chars[m], i, j + m};
      wl.char_positions.push_back(cp);
    }
  } else if(direction == CheckDirection::kVertical) {
    wl.word = word;
    for(unsigned m = 0; m < chars.size(); m++) {
      CharPositions cp{chars[m], i + m, j};
      wl.char_positions.push_back(cp);
    }
  } else if(direction == CheckDirection::kRightDiag) {
    wl.word = word;
    for(unsigned m = 0; m < chars.size(); m++) {
      CharPositions cp{chars[m], i + m, j + m};
      wl.char_positions.push_back(cp);
    }
  } else if(direction == CheckDirection::kLeftDiag) {
    wl.word = word;
    for(unsigned m = 0; m < chars.size(); m++) {
      CharPositions cp{chars[m], i + m, j - m};
      wl.char_positions.push_back(cp);
    }
  }
  return wl;
}

WordLocation WordSearchSolver::FindWord(const std::string& word, CheckDirection direction) {
  std::vector<char> chars(word.begin(), word.end());
  if(direction == CheckDirection::kHorizontal) {
    for(unsigned i = 0; i < puzzle_height_; i++) {
      for(unsigned j = 0; j < puzzle_width_; j++) {
        if(CheckHorizontal(chars, i, j, puzzle_)) {
          return GetWordLocation(word, chars, i, j, direction);
        }
      }
    }
  } else if(direction == CheckDirection::kVertical) {
    for(unsigned i = 0; i < puzzle_height_; i++) {
      for(unsigned j = 0; j < puzzle_width_; j++) {
        if(CheckVertical(chars, i, j, puzzle_)) {
          return GetWordLocation(word, chars, i, j, direction);
        }
      }
    }
  } else if(direction == CheckDirection::kRightDiag) {
    for(unsigned i = 0; i < puzzle_height_; i++) {
      for(unsigned j = 0; j < puzzle_width_; j++) {
        if(CheckRightDiag(chars, i, j, puzzle_)) {
          return GetWordLocation(word, chars, i, j, direction);
        }
      }
    }
  } else if(direction == CheckDirection::kLeftDiag) {
    for(unsigned i = 0; i < puzzle_height_; i++) {
      for(unsigned j = 0; j < puzzle_width_; j++) {
        if(CheckLeftDiag(chars, i, j, puzzle_)) {
          return GetWordLocation(word, chars, i, j, direction);
        }
      }
    }
  }
  return WordLocation{};
}

bool WordSearchSolver::CheckHorizontal(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle) {
  for(unsigned i = 0; i < chars.size(); i++) {
    if(!LocationInBounds(row, col + i) || puzzle[row][col + i] != chars[i]) {
      return false;
    }
  }
  return true;
}

bool WordSearchSolver::CheckVertical(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle) {
  for(unsigned i = 0; i < chars.size(); i++) {
    if(!LocationInBounds(row + i, col) || puzzle[row + i][col] != chars[i]) {
      return false;
    }
  }
  return true;
}

bool WordSearchSolver::CheckRightDiag(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle) {
  for(unsigned i = 0; i < chars.size(); i++) {
    if(!LocationInBounds(row + i, col + i) || puzzle[row + i][col + i] != chars[i]) {
      return false;
    }
  }
  return true;
}

bool WordSearchSolver::CheckLeftDiag(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle) {
  for(unsigned i = 0; i < chars.size(); i++) {
    if(!LocationInBounds(row + i, col - i) || puzzle[row + i][col - i] != chars[i]) {
      return false;
    }
  }
  return true;
}