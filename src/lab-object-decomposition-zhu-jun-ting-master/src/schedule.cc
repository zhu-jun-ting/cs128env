#include "schedule.hpp"

#include "appointment.hpp"

#include "hospital.hpp"
#include "timeslot.hpp"


bool Schedule::IsAvailable(TimeSlot time) const {
  for (TimeSlot busy : times_) {
    if (busy.startTime == time.startTime) {
      return false;
    } else if (busy.endTime > time.startTime &&
               busy.startTime <= time.startTime) {
      return false;
    } else if (busy.startTime > time.startTime) {
      return time.endTime < busy.startTime;
    }
  }
  return true;
}
  

void Schedule::MarkAvailable(TimeSlot time) {
  for (const TimeSlot& slot : times_) {
    if (time.startTime == slot.startTime && time.endTime == slot.endTime) {
      times_.erase(slot);
      return;
    }
  }
}
void Schedule::MarkBusy(TimeSlot time) {
  if (!IsAvailable(time)) {
    return;
  }
  times_.insert(time);
}