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

StudentRecords::StudentRecords(int i, string n, string l, string m, double g, int a) { // overloaded constructor
    id = i;
    name = n;
    level = l;
    major = m;
    gpa = g;
    advisorID = a;
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
 * @param i an integer representing the ID of the student. 
 */
void StudentRecords::setID(int i) {
    id = i;
}

/**
 * sets the private member: name.
 * @param n a string representing the name of the student.
 */
void StudentRecords::setName(string n) {
    name = n;
}

/** 
 * sets the private member: level.
 * @param l a string representing the level of the student.
 * examples: freshman, sophomore, junior, senior, etc.
 */
void StudentRecords::setLevel(string l) {
    level = l;
}

/**
 * sets the private member: major.
 * @param m a string representing the major of the student.
 */
void StudentRecords::setMajor(string m) {
    major = m;
}

/** 
 * sets the private member: gpa.
 * @param g a double representing the GPA of the student. 
 */
void StudentRecords::setGPA(double g) {
    gpa = g;
}

/**
 * sets the private member: advisorID.
 * @param a an integer representing the ID of the student's advisor (faculty). 
 */
void StudentRecords::setAdvisorID(int a) {
    advisorID = a;
}