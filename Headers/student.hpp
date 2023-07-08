#include <string>

class Student {
  private:
    std::string name;
    int age;
    int id;
  public:
    Student(std::string name, int age);
    void SetName(std::string newName);
    std::string GetName();
    void SetAge(int newAge);
    int GetAge();
    int GetId();
};
