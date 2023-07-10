#include "../Headers/dataBase.hpp"
#include <fstream>
#include <string>

db::SQLite::SQLite(std::string fileName) {
  this->fileName = fileName + ".db";
}

bool db::SQLite::CreateDataBase(std::string tableQuerry) {
  if (!std::ifstream(fileName)) {    
    std::ofstream of(fileName);
    this->ExecuteSQL(tableQuerry);

    return (std::ifstream(fileName)) ? true : false;
  }
  return false;
}

bool db::SQLite::ConnectDataBase() {\
  if (!std::ifstream(fileName)) {
    return false;
  }
  const char* charFileName = fileName.c_str();
  int response = sqlite3_open(charFileName, &db);
  if (response != SQLITE_OK) {
    return false;
  }
  return true;
}

void db::SQLite::DisconnectDataBase() {
  sqlite3_close(db);
}

std::string db::SQLite::ExecuteSQL(std::string querry) {
  std::string data;
  int response = sqlite3_exec(db, querry.c_str(), NULL, (void*)data.c_str(), NULL);
  if (response != SQLITE_OK) {
    return "err";
  }
  return data;
}
