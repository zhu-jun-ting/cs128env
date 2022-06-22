#include "roster_iterator.hpp"

Student RosterIterator::operator*() { return current_->student; }

bool RosterIterator::operator==(const RosterIterator& other) const {
  return current_ == other.current_;
}

bool RosterIterator::operator!=(const RosterIterator& other) const {
  return !(*this == other);
}

RosterIterator& RosterIterator::operator++() {
  if (current_) {
    current_ = current_->next.get();
  }
  return *this;
}

RosterIterator RosterIterator::operator++(int) {
  auto clone(*this);
  if (current_) {
    current_ = current_->next.get();
  }
  return clone;
}
