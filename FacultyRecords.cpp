/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
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

// mutators
/**
 * sets the private member: id.
 * @param id an integer representing the ID of the faculty member. 
 */
void FacultyRecords::setID(int id) {
    this->id = id;
}

/**
 * sets the private member: name.
 * @param name a string representing the name of the faculty member. 
 */
void FacultyRecords::setName(string name) {
    this->name = name;
}

/**
 * sets the private member: level.
 * @param level a string representing the level of the faculty member. 
 * examples: lecturer, assistant professor, associate professor, etc.
 */
void FacultyRecords::setLevel(string level) {
    this->level = level;
}

/**
 * sets the private member: department.
 * @param department a string representing the department of the faculty member. 
 */
void FacultyRecords::setDepartment(string department) {
    this->department = department;
}
