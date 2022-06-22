std::vector<Appointment> appointments_;
std::vector<Doctor*> doctors_;
Schedule schedule_;
std::set<TimeSlot> times_;

void AddAppointment(TimeSlot time, std::string patient);
void AddAppointment(TimeSlot time);
void AddDoctor(Doctor& d);
Doctor* GetAvailableDoctor(TimeSlot time);
bool IsAvailable(TimeSlot time) const;
bool IsAvailable(TimeSlot time) const;
void MarkAvailable(TimeSlot time);
void MarkBusy(TimeSlot time);
void RemoveAppointment(TimeSlot time);
void RemoveAppointment(TimeSlot time, std::string patient);
