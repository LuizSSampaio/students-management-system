#include <fstream>
#include <string>
#include <sqlite3.h>

namespace db{
  class SQLite {
  private:
    std::string fileName;
    sqlite3* db;
  public:
    SQLite(std::string fileName);
    bool CreateDataBase(std::string tableQuerry);
    bool ConnectDataBase();
    void DisconnectDataBase();
    std::string ExecuteSQL(std::string querry);
  };
}

