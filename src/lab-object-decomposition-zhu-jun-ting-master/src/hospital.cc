#include "hospital.hpp"

#include "appointment.hpp"
#include "doctor.hpp"

void Hospital::AddAppointment(TimeSlot time, std::string patient) {
  Doctor* doctor = GetAvailableDoctor(time);
  if (doctor == nullptr) {
    return;

    
  }
  Appointment appo = {patient, doctor, time};
  doctor->AddAppointment(time);
  appointments_.push_back(appo);
}

Doctor* Hospital::GetAvailableDoctor(TimeSlot time) {
  for (Doctor* doctor : doctors_) {
    if (doctor->IsAvailable(time)) {
      return doctor;
    }
  }
  return nullptr;
}

void Hospital::AddDoctor(Doctor& d) { doctors_.push_back(&d); }

void Hospital::RemoveAppointment(TimeSlot time, std::string patient) {
  for (auto a = appointments_.begin(); a != appointments_.end(); a++) {
    Appointment& appo = *a;
    if (appo.timeslot == time && appo.patient == patient) {
      appo.doctor->RemoveAppointment(time);
      appointments_.erase(a);
      return;
    }
  }
}