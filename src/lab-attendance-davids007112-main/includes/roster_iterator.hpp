#ifndef ROSTER_ITERATOR_HPP
#define ROSTER_ITERATOR_HPP

#include <iterator>
#include <string>

#include "roster_entry.hpp"
typedef std::string Student;

class RosterIterator : std::iterator<std::forward_iterator_tag, Student> {
 public:
  RosterIterator() : current_(nullptr){};
  RosterIterator(RosterEntry* ptr) : current_(ptr){};
  Student operator*();
  bool operator==(const RosterIterator& other) const;
  bool operator!=(const RosterIterator& other) const;
  RosterIterator& operator++();
  RosterIterator operator++(int);

 private:
  RosterEntry* current_;
};

#endif