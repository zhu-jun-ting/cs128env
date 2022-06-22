#ifndef ROSTER_ENTRY_HPP
#define ROSTER_ENTRY_HPP

#include <memory>
#include <string>

typedef std::string Student;

struct RosterEntry {
  RosterEntry(const Student& student, RosterEntry* next)
      : student(student), next(next){};
  Student student;
  std::unique_ptr<RosterEntry> next;
};

#endif