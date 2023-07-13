#include <string>
//#include <memory>
//#include "dataBase.hpp"

class Student
{
private:
  std::string name;
  int age;
  int id;

public:
  Student(std::string name, int age/*, std::shared_ptr<db::SQLite> database*/);
  void SetName(std::string newName);
  std::string GetName();
  void SetAge(int newAge);
  int GetAge();
  int GetId();
  //void UpdateDatabase(std::shared_ptr<db::SQLite> database);
};
