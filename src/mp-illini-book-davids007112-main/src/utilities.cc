#include "utilities.hpp"

// Provided to you. Do not edit!

std::vector<std::string> utilities::Split(const std::string& str, char delimiter) {
  size_t last = 0;
  std::vector<std::string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter || str.at(i) == '\r') {
      std::string substr = str.substr(last, i - last);
      last = i + 1;
      substrs.push_back(substr);
    }
  }

  if (last != str.size()) {
    std::string substr = str.substr(last, str.length() - last);
    substrs.push_back(substr);
  }

  return substrs;
}
