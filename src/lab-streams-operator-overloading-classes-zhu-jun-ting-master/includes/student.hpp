#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "course.hpp"
#include <iostream>
#include <string>
#include <vector>

class Student {
public:
  Student(std::string name, std::string uin, std::string net_id);
  Student(std::string name,
          std::string uin,
          std::string net_id,
          std::string major,
          std::vector<Course> courses,
          bool graduated);
  std::string GetName() const;
  std::string GetUIN() const;
  std::string GetNetId() const;
  std::string GetMajor() const;
  bool HasGraduated() const;
	int GetCredit() const;
	const std::vector<Course>& GetCourses() const;
  void SetName(std::string name);
  void SetMajor(std::string major);
  bool AddCourse(Course c);
  void Graduate();

private:
  std::string name_;
  std::string uin_;
  std::string net_id_;
  std::string major_;
  bool graduated_;
  std::vector<Course> courses_;
  static const int kMinCreditsGrad = 120;
};

std::ostream& operator<<(std::ostream& os, const Student& s);
std::ostream& operator<<(std::ostream& os, const std::vector<Course>& v);

#endif