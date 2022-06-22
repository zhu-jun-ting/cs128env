#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP
#include <set>
#include <string>
#include <vector>

#include "timeslot.hpp"

class Schedule {
public:
  Schedule() = default;
  bool IsAvailable(TimeSlot time) const;
  void MarkAvailable(TimeSlot time);
  void MarkBusy(TimeSlot time);



private:
  std::set<TimeSlot> times_;
};

#endif