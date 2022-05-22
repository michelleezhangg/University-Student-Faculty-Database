/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the FacultyRecords class.
*/

#include "FacultyRecords.h"

FacultyRecords::FacultyRecords() { // default constructor
    int id = -1;
    name = "";
    level = "";
    department = "";
    studentIDs = new vector<int>();
}

FacultyRecords::FacultyRecords(int i, string n, string l, string d, vector<int> *sid) { // overloaded constructor
    id = i;
    name = n;
    level = l;
    department = d;
    studentIDs = sid;
}

FacultyRecords::~FacultyRecords() { // destructor
    delete studentIDs;
}

// accessors
/** @return id an integer representing the ID of the faculty member. */
int FacultyRecords::getID() {
    return id;
}

/** @return name a string representing the name of the faculty member. */
string FacultyRecords::getName() {
    return name;
}

/** 
 * @return level a string representing the level of the faculty member.
 * examples: lecturer, assistant professor, associate professor, etc.
 */
string FacultyRecords::getLevel() {
    return level;
}

/** @return department a string representing the department of the faculty member. */
string FacultyRecords::getDepartment() {
    return department;
}

/** @return studentIDs a vector representing the collection of the faculty's students' IDs. */
vector<int> FacultyRecords::getStudentIDs() {
    return *studentIDs;
}

// mutators
/**
 * sets the private member: id.
 * @param i an integer representing the ID of the faculty member. 
 */
void FacultyRecords::setID(int i) {
    id = i;
}

/**
 * sets the private member: name.
 * @param n a string representing the name of the faculty member. 
 */
void FacultyRecords::setName(string n) {
    name = n;
}

/**
 * sets the private member: level.
 * @param l a string representing the level of the faculty member. 
 * examples: lecturer, assistant professor, associate professor, etc.
 */
void FacultyRecords::setLevel(string l) {
    level = l;
}

/**
 * sets the private member: department.
 * @param d a string representing the department of the faculty member. 
 */
void FacultyRecords::setDepartment(string d) {
    department = d;
}

/**
 * sets the private member: department.
 * @param sid a vector representing the collection of the faculty's students' IDs. 
 */
void FacultyRecords::setStudentIDs(vector<int> *sid) {
    studentIDs = sid;
}
