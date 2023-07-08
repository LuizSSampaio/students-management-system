#include "../Headers/student.hpp"
#include <string>

Student::Student(std::string name, int age) {
  this->name = name;
  this->age = age;
}

void Student::SetName(std::string newName) {
  name = newName;
}

std::string Student::GetName() {
  return name;
}

void Student::SetAge(int newAge) {
  age = newAge;
}

int Student::GetAge() {
  return age;
}

int Student::GetId() {
  return id;
}
