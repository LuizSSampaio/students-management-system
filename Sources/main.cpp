#include <iostream>
#include <string>
#include "../Headers/student.hpp"
#include "../Headers/dataBase.hpp"

void Choices();
bool AddStudent(std::string name, int age);
bool EditStudent(Student student, std::string newName = "", int newAge = 0);
bool AddSubject(std::string subjectName);
bool SetStudentSubjectGrade(Student student, std::string subject, int newGrade);
bool ShowStudentList();
bool ShowStudentData(Student student); 

int main (int argc, char *argv[]) {
  std::cout << "=== Students Management System ===" << "\n";
  Choices();
  return 0;
}

void Choices() {
  bool bInvalidChoice = false;
  do {
    int choice;
    std::cout << "[1] - Add Student" << '\n'
      << "[2] - Edit Student" << '\n'
      << "[3] - Add Subject" << '\n'
      << "[4] - Set Student Subject Grade" << '\n'
      << "[5] - View Student List" << '\n'
      << "[6] - View Student Data" << '\n'
      << "Enter your choice number: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        //AddStudent(name, age);
        bInvalidChoice = false;
        break;
      case 2:
        //EditStudent(student);
        bInvalidChoice = false;
        break;
      case 3:
        //AddSubject(subjectName);
        bInvalidChoice = false;
        break;
      case 4:
        //SetStudentSubjectGrade(student, subject, newGrade);
        bInvalidChoice = false;
        break;
      case 5:
        //ShowStudentList();
        bInvalidChoice = false;
        break;
      case 6:
        //ShowStudentData(student);
        bInvalidChoice = false;
        break;
      default:
        bInvalidChoice = true;
    }
  } while (bInvalidChoice);
}
