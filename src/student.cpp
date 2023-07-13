#include <string>
// #include <memory>
#include "student.hpp"
// #include "dataBase.hpp"

Student::Student(std::string name, int age /*, std::shared_ptr<db::SQLite> database*/)
{
  this->name = name;
  this->age = age;
}

void Student::SetName(std::string newName)
{
  name = newName;
}

std::string Student::GetName()
{
  return name;
}

void Student::SetAge(int newAge)
{
  age = newAge;
}

int Student::GetAge()
{
  return age;
}

int Student::GetId()
{
  return id;
}

/*
void Student::UpdateDatabase(std::shared_ptr<db::SQLite> database)
{
}
*/