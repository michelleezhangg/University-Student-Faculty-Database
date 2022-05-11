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

Faculty::Faculty(int i, string n, string l, string d) { // overloaded constructor
    id = i;
    name = n;
    level = l;
    department = d;
    studentIDs = new vector<int>();
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
    return *studentIDs;
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

// functions
/**
 * prints out all of the faculty member's advisees.
 */
void Faculty::printAdvisees() {
    if (studentIDs->size() == 0)
        cout << "This faculty member has no advisees." << endl;

    else {
        cout << "Advisees IDs: " << endl;

        for (int i = 0; i < studentIDs->size(); ++i) {
            if (i == studentIDs->size() - 1)
                cout << studentIDs->at(i) << endl;
            else
                cout << studentIDs->at(i) << ", ";
        }
    }
}

ostream& operator << (ostream &os, const Faculty &f) {
    os << "Faculty information" << "\n";
    os << "ID: " << f.id << "\n";
    os << "Name: " << f.name << "\n";
    os << "Level: " << f.level << "\n";
    os << "Department: " << f.department << "\n";
    os << "Advisees IDs: ";

    for (int i = 0; i < f.studentIDs->size(); ++i) {
        if (i == f.studentIDs->size() - 1)
            os << f.studentIDs->at(i) << "\n";
        else
            os << f.studentIDs->at(i) << ", ";
    }

    return os;
}