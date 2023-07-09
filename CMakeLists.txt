cmake_minimum_required(VERSION 3.22.1)
project(StudentsManagementSystem)

# Find SQLite librarie
find_package(SQLite3 REQUIRED)

# Set source files
set(SOURCES Sources/main.cpp Sources/student.cpp Sources/dataBase.cpp)

# Create project executable
add_executable(StudentsManagementSystem ${SOURCES})

# SQLITE3
target_include_directories(StudentsManagementSystem PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(StudentsManagementSystem PRIVATE ${SQLite3_LIBRARIES})
