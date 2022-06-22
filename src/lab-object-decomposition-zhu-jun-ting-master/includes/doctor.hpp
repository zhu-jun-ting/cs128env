#ifndef DOCTOR_HPP
#define DOCTOR_HPP




#include "schedule.hpp"
#include <set>
#include <string>
#include <vector>

class Doctor {
public:
  Doctor() = default;
  
  void RemoveAppointment(TimeSlot time);
  void AddAppointment(TimeSlot time);
  bool IsAvailable(TimeSlot time) const;

private:
  Schedule schedule_;
};

#endif