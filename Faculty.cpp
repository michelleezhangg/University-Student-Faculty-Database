/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
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

/** @return numAdvisees an integer representing the number of advisees this faculty member has. */
int Faculty::getNumAdvisees() {
    return numAdvisees;
}

/** @return studentIDs a vector representing the collection of faculty member's student advisees' IDs. */
vector<int> Faculty::getAdviseeIDs() {
    return *studentIDs;
}

// mutators
/**
 * sets the department of the faculty member.
 * @param d a string representing the department of the faculty member.
 */
void Faculty::setDepartment(string d) {
    department = d;
}

/**
 * sets the student ID vector of the faculty member.
 * @param sid a vector representing the collection of faculty member's student advisees' IDs.
 */
void Faculty::setAdviseesIDs(vector<int> *sid) {
    studentIDs = sid;
}

// functions
/**
 * returns all of the faculty member's advisees.
 * handles the case when the faculty member has no advisees.
 * @return advisees a string representing the faculty member's advisees.
 */
string Faculty::getAdviseesIDs() {
    string advisees = "";
    if (studentIDs->size() == 0)
        return "This faculty member has no advisees.\n";

    else {
        advisees += "Advisees IDs:\n";

        for (int i = 0; i < studentIDs->size(); ++i) {
            if (i == studentIDs->size() - 1)
                advisees += to_string(studentIDs->at(i)) + "\n";
            else
                advisees += to_string(studentIDs->at(i)) + ", ";
        }
    }

    return advisees;
}

/**
 * gets the faculty member's information in the form of a string.
 * @return faculty_info a string representing the faculty member's information.
 */
string Faculty::getFacultyInfo() {
    string faculty_info = "";

    faculty_info += "Faculty Information\n";
    faculty_info += "ID: " + to_string(id) + "\n";
    faculty_info += "Name: " + name + "\n";
    faculty_info += "Level: " + level + "\n";
    faculty_info += "Department: " + department + "\n";
    faculty_info += getAdviseesIDs();

    return faculty_info;
}

/**
 * overloads the operator << for a Faculty object.
 * @param f a Faculty object we wish to retrieve information from.
 */
ostream& operator << (ostream &os, const Faculty &f) {
    os << "Faculty Information" << "\n";
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

/**
 * adds an advisee ID to the vector of student IDs.
 * @param id an integer representing the ID to add.
 */
void Faculty::addAdvisee(int id) {
    studentIDs->push_back(id);
}

/**
 * removes an advisee ID from the vector of student IDs.
 * @param id an integer representing the ID to remove.
 */
void Faculty::removeAdvisee(int id) {
    for (int i = 0; i < studentIDs->size(); ++i) {
        if (studentIDs->at(i) == id)
            studentIDs->erase(studentIDs->begin() + i); // https://www.cplusplus.com/reference/vector/vector/erase/
    }
}

/**
 * sets the number of advisees a faculty member has.
 * @param na an integer representing the number of advisees a faculty member has.
 */
void Faculty::setNumAdvisees(int na) {
    numAdvisees = na;
}