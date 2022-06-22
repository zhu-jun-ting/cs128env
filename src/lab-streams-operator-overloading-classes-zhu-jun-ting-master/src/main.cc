#include "student.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <ostream>

int main() {
  Student st("Ike South", "000000000", "ike");

  Course c;
  c.name = "AAA 111";
  c.credits = 3;
  st.AddCourse(c);
  
  std::cout << st;
}
