#include <iostream>
#include <memory>

#include "roster.hpp"

using namespace std;

Roster::Roster(const Student& student) {
  // TODO
  head_ = make_unique<RosterEntry>(student, nullptr);
}

void Roster::AddStudent(const Student& student) {
  // TODO
  if (head_ == nullptr) {
    head_ = make_unique<RosterEntry>(student, nullptr);
    return;
  }

  RosterEntry* cur = head_.get();
  unique_ptr<RosterEntry> stu(make_unique<RosterEntry>(student, nullptr));

  if (cur->next == nullptr && student < cur->student) {
    stu->next = move(head_);
    head_ = move(stu);
    return;
  }

  if (cur->next == nullptr && student >= cur->student) {
    head_->next = move(stu);
    return;
  }

  while (cur != nullptr && cur->next != nullptr) {
    if (cur->student <= student && student <= cur->next->student) {
      stu->next = move(cur->next);
      cur->next = move(stu);
      return;
    }
    cur = cur->next.get();
  }

  cur->next = move(stu);

}

Roster::Iterator Roster::begin() const { 
  return Iterator(head_.get()); 
}

Roster::Iterator Roster::end() const { 
  return Iterator(); 
}
