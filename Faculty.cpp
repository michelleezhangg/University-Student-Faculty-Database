/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Faculty Class.
* This class inherits from Person Class.
*/

#include "Faculty.h"

Faculty::Faculty() { // default constructor
    department = "";
    studentIDs = new vector<int>();
    fr = new FacultyRecords();
}

Faculty::Faculty(int i, string n, string l, string d, vector<int> *sid) { // overloaded constructor
    id = i;
    name = n;
    level = l;
    department = d;
    fr = new FacultyRecords(id, name, level, department, studentIDs);
}

Faculty::~Faculty() { // destructor
    delete fr;
    delete studentIDs;
}

// accessors
/** @return department a string representing the department of the faculty member. */
string Faculty::getDepartment() {
    return department;
}

/** @return studentIDs a vector representing the collection of faculty member's student advisees' IDs. */
vector<int> Faculty::getStudentIDs() {
    return studentIDs;
}

// mutators
/**
 * sets the private member: department.
 * @param d a string representing the department of the faculty member.
 */
void Faculty::setDepartment(string d) {
    department = d;
}

/**
 * sets the private member: studentIDs.
 * @param sid a vector representing the collection of faculty member's student advisees' IDs.
 */
void Faculty::setStudentIDs(vector<int> *sid) {
    studentIDs = sid;
}