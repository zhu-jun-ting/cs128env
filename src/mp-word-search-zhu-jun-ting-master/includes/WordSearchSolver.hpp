#ifndef WORDSEARCHSOLVER_HPP
#define WORDSEARCHSOLVER_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "WordLocation.hpp"

enum class CheckDirection { kHorizontal, kVertical, kLeftDiag, kRightDiag };

class WordSearchSolver {
public:
  WordSearchSolver(const std::vector<std::vector<char>>& puzzle);
  WordLocation FindWord(const std::string& word);
  WordLocation FindWord(const std::string& word, CheckDirection direction);

private:
  bool LocationInBounds(size_t row, size_t col) const;
  std::vector<std::vector<char>> puzzle_;
  size_t puzzle_height_;
  size_t puzzle_width_;

  bool CheckHorizontal(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle);
  bool CheckVertical(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle);
  bool CheckLeftDiag(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle);
  bool CheckRightDiag(const std::vector<char>& chars, size_t row, size_t col, const std::vector<std::vector<char>>& puzzle);

  WordLocation GetWordLocation(const std::string& word, const std::vector<char>& chars, size_t i, size_t j, CheckDirection direction);
};

#endif