#include "StudentRecords.h"

StudentRecords::StudentRecords() { // default constructor
    id = -1;
    name = "";
    level = "";
    major = "";
    gpa = 0.0;
    advisorID = -1;
}

StudentRecords::StudentRecords(int id, string name, string level, string major, double gpa, int advisorID) { // overloaded constructor
    this->id = id;
    this->name = name;
    this->level = level;
    this->major = major;
    this->gpa = gpa;
    this->advisorID = advisorID;
}

StudentRecords::~StudentRecords() {} // destructor

// accessors
int StudentRecords::getID() {
    return id;
}

string StudentRecords::getName() {
    return name;
}

string StudentRecords::getLevel() {
    return level;
}

string StudentRecords::getMajor() {
    return major;
}

double StudentRecords::getGPA() {
    return gpa;
}

int StudentRecords::getAdvisorID() {
    return advisorID;
}

// mutators
void StudentRecords::setID(int id) {
    this->id = id;
}

void StudentRecords::setName(string name) {
    this->name = name;
}

void StudentRecords::setLevel(string level) {
    this->level = level;
}

void StudentRecords::setMajor(string major) {
    this->major = major;
}

void StudentRecords::setGPA(double gpa) {
    this->gpa = gpa;
}

void StudentRecords::setAdvisorID(int advisorID) {
    this->advisorID = advisorID;
}