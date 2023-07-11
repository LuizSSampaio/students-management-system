#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include "../Headers/student.hpp"
#include "../Headers/dataBase.hpp"

void Choices(std::shared_ptr<db::SQLite> dataBase);
bool AddStudent(std::shared_ptr<db::SQLite> dataBase);
bool EditStudent(std::shared_ptr<db::SQLite> dataBase);
bool AddSubject(std::string subjectName);
bool SetStudentSubjectGrade(Student student, std::string subject, int newGrade);
bool ShowStudentList();
bool ShowStudentData(Student student);
void ShowError(std::string error);

int main (int argc, char *argv[]) {
  std::cout << "=== Students Management System ===" << "\n";
  std::shared_ptr<db::SQLite> dataBase = std::make_shared<db::SQLite>("data");
  if (!dataBase->ConnectDataBase()) {
    std::string CreateTablequerry {
      "CREATE TABLE 'STUDENTS' ("
      " 'ID' INTEGER UNIQUE,"
      " 'NAME' TEXT NOT NULL,"
      " 'AGE' INTEGER NOT NULL,"
      " 'GRADES' TEXT,"
      " PRIMARY KEY('ID' AUTOINCREMENT)"
      ");"
    };
    if (dataBase->CreateDataBase(CreateTablequerry)) {
      if (!dataBase->ConnectDataBase()) {
        ShowError("Fail to connect with the database");
      }
    } else {
      ShowError("Fail to create the database file");
    }
  }
  Choices(dataBase);
  dataBase->DisconnectDataBase();
  return 0;
}

void Choices(std::shared_ptr<db::SQLite> dataBase) {
  bool bInvalidChoice { false };
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
        AddStudent(dataBase);
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

//TODO: Change questions about the students to student class functions
// All changes in database will be done in the student class

bool AddStudent(std::shared_ptr<db::SQLite> dataBase) {
  std::string name;
  std::cout << "Enter the name of the new student: ";
  std::cin >> name;

  std::string age;
  std::cout << "Enter the age of the new student: ";
  std::cin >> age;

  std::string querry {
    "INSERT INTO STUDENTS (NAME, AGE)" 
    "VALUES" 
    "('" + name + "', " + age + " );"
  };
  std::string response = dataBase->ExecuteSQL(querry);
  return !(response == "err");
}

//TODO: STUDENT identification by ID
bool EditStudent(std::shared_ptr<db::SQLite> dataBase) {
  std::string newName;
  std::cout << "Enter the new name of the student: ";
  std::cin >> newName;

  std::string newAge;
  std::cout << "Enter the new age of the student: ";
  std::cin >> newAge;

  std::string querry {
    ""
    //"UPDATE STUDENTS set NAME = '" + newName + "' where ID=?;"
    //"UPDATE STUDENTS set AGE = " + newAge + " where ID=?;"
  };
  std::string response = dataBase->ExecuteSQL(querry);
  return !(response == "err");
}

void ShowError(std::string error) {
  std::cout << "Error: " << error << '\n';
  std::cout << "Please restart your program...";
}
