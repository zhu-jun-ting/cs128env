#ifndef ROSTER_HPP
#define ROSTER_HPP

#include <iterator>
#include <memory>
#include <string>

#include "roster_entry.hpp"
#include "roster_iterator.hpp"

typedef std::string Student;

class Roster {
 public:
  using Iterator = RosterIterator;

  Roster() : head_(nullptr){};
  Roster(const Student& student);
  void AddStudent(const Student& student);

  Iterator begin() const;
  Iterator end() const;

 private:
  std::unique_ptr<RosterEntry> head_;
};

#endif
