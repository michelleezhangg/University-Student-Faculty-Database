#include "FacultyRecords.h"

FacultyRecords::FacultyRecords() { // default constructor
    int id = -1;
    name = "";
    level = "";
    department = "";
    studentIDs = new vector<int>();
}

FacultyRecords::FacultyRecords(int id, string name, string level, string department) { // overloaded constructor
    this->id = id;
    this->name = name;
    this->level = level;
    this->department = department;
    studentIDs = new vector<int>();
}

FacultyRecords::~FacultyRecords() { // destructor
    delete studentIDs;
}

// accessors
int FacultyRecords::getID() {
    return id;
}

string FacultyRecords::getName() {
    return name;
}

string FacultyRecords::getLevel() {
    return level;
}

string FacultyRecords::getDepartment() {
    return department;
}

// mutators
void FacultyRecords::setID(int id) {
    this->id = id;
}

void FacultyRecords::setName(string name) {
    this->name = name;
}

void FacultyRecords::setLevel(string level) {
    this->level = level;
}

void FacultyRecords::setDepartment(string department) {
    this->department = department;
}
