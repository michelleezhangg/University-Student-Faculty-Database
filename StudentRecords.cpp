/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the StudentRecords class.
*/

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
/** @return id an integer representing the ID of the student. */
int StudentRecords::getID() {
    return id;
}

/** @return name a string representing the name of the student. */
string StudentRecords::getName() {
    return name;
}

/** 
 * @return level a string representing the level of the student.
 * examples: freshman, sophomore, junior, senior, etc.
 */
string StudentRecords::getLevel() {
    return level;
}

/** @return major a string representing the major of the student. */
string StudentRecords::getMajor() {
    return major;
}

/** @return gpa a double representing the GPA of the student. */
double StudentRecords::getGPA() {
    return gpa;
}

/** @return advisorID an integer representing the ID of the student's advisor (faculty). */
int StudentRecords::getAdvisorID() {
    return advisorID;
}

// mutators
/** 
 * sets the private member: id.
 * @param id an integer representing the ID of the student. 
 */
void StudentRecords::setID(int id) {
    this->id = id;
}

/**
 * sets the private member: name.
 * @param name a string representing the name of the student.
 */
void StudentRecords::setName(string name) {
    this->name = name;
}

/** 
 * sets the private member: level.
 * @param level a string representing the level of the student.
 * examples: freshman, sophomore, junior, senior, etc.
 */
void StudentRecords::setLevel(string level) {
    this->level = level;
}

/**
 * sets the private member: major.
 * @param major a string representing the major of the student.
 */
void StudentRecords::setMajor(string major) {
    this->major = major;
}

/** 
 * sets the private member: gpa.
 * @param gpa a double representing the GPA of the student. 
 */
void StudentRecords::setGPA(double gpa) {
    this->gpa = gpa;
}

/**
 * sets the private member: advisorID.
 * @param advisorID an integer representing the ID of the student's advisor (faculty). 
 */
void StudentRecords::setAdvisorID(int advisorID) {
    this->advisorID = advisorID;
}