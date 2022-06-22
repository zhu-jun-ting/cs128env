#include "color.hpp"
#include <stdexcept>

Color::Color(int r, int g, int b): red_(r), green_(g), blue_(b) {
  // need to ensure valid color has been constructed...
  if(!IsValid(r) || !IsValid(g) || !IsValid(b)) {
    throw std::invalid_argument("invalid rgb value");
  }
}

// do not modify
bool operator==(const Color& rhs, const Color& lhs) {
  return (rhs.Red() == lhs.Red() && rhs.Green() == lhs.Green() &&
          rhs.Blue() == lhs.Blue());
}

bool Color::IsValid(int c) const {
  return c >= 0 && c <= kMax;
}