#include "student.hpp"
#include "course.hpp"
#include <iostream>
#include <string>
#include <vector>

Student::Student(std::string name, std::string uin, std::string net_id):
	name_(name), uin_(uin), net_id_(net_id),  major_("Undeclared"), graduated_(false) {

}

Student::Student(std::string name, std::string uin, std::string net_id, std::string major, std::vector<Course> courses, bool graduated):
	name_(name), uin_(uin), net_id_(net_id),  major_(major), graduated_(graduated), courses_(courses) {

}

void Student::SetName(std::string name) { name_ = name; }
void Student::SetMajor(std::string major) { major_ = major; }
std::string Student::GetName() const { return name_; }
std::string Student::GetUIN() const { return uin_; }
std::string Student::GetMajor() const { return major_; }
std::string Student::GetNetId() const { return net_id_; }
bool Student::HasGraduated() const { return graduated_; }
const std::vector<Course>& Student::GetCourses() const { return courses_; }

bool Student::AddCourse(Course c) {
	for(Course course: courses_) {
		if(course.name == c.name) {
			return false;
		}
	}
	courses_.push_back(c);
	return true;
}

void Student::Graduate() {
	if(GetCredit() >= kMinCreditsGrad) {
		graduated_ = true;
	}
}

int Student::GetCredit() const {
	int credit = 0;
	for(Course course: courses_) {
		credit += course.credits;
	}
	return credit;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
	os << "Name: " << s.GetName() << "\n";
	os << "UIN: " << s.GetUIN() << "\n";
	os << "Net Id: " << s.GetNetId() << "\n";
	os << "Major: " << s.GetMajor() << "\n";
	os << "Credits: " << s.GetCredit() << "\n";
	os << "Courses: " << s.GetCourses() << "\n";
	os << "Graduated: " << (s.HasGraduated() ? "True" : "False");
	return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Course>& v) {
	std::string s;
	for(Course course: v) {
		s += course.name + ", ";
	}
	os << s.substr(0, s.size() - 2);
	return os;
}