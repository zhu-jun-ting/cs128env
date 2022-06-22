#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include "appointment.hpp"
#include "timeslot.hpp"
#include <set>
#include <string>
#include <vector>



class Hospital {
public:
  Hospital() = default;
  void AddAppointment(TimeSlot time, std::string patient);
  Doctor* GetAvailableDoctor(TimeSlot time);
  void AddDoctor(Doctor& d);
  void RemoveAppointment(TimeSlot time, std::string patient);

private:
std::vector<Appointment> appointments_;
std::vector<Doctor*> doctors_;
};

#endif