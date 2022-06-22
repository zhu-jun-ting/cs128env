#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <string>



#include "doctor.hpp"
#include "timeslot.hpp"

struct Appointment {
  std::string patient;
  Doctor* doctor;
  TimeSlot timeslot;
};

#endif