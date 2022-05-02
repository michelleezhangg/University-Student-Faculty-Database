/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Student Class.
*/

#include "Student.h"

Student::Student() { // default constructor
    sr = new StudentRecords();
}

Student::~Student() { // destructor
    delete sr;
}

// overloaded operator
/**
 * overloads the operator == for the Student class.
 * @param s a Student to compare with operator ==
 * @return true if the students are equal (their IDs are equal).
 * @return false if the students are not equal (their IDs are not equal).
 */
bool Student::operator == (Student *s) {
    return this->sr->getID() == s->sr->getID();
}

/**
 * overloads the operator != for the Student class.
 * @param s a Student to compare with operator !=
 * @return true if the students are not equal (their IDs are not equal).
 * @return false if the students are equal (their IDs are equal).
 */
bool Student::operator != (Student *s) {
    return this->sr->getID() != s->sr->getID();
}

/**
 * overloads the operator > for the Student class.
 * @param s a Student to compare with operator >
 * @return true if the left student is greater than the right student (left student ID > right student ID).
 * @return false if the left student is not greater than the right student.
 */
bool Student::operator > (Student *s) {
    return this->sr->getID() > s->sr->getID();
}

/**
 * overloads the operator < for the Student class.
 * @param s a Student to compare with operator <
 * @return true if the left student is less than the right student (left student ID < right student ID).
 * @return false if the left student is not less than the right student.
 */
bool Student::operator < (Student *s) {
    return this->sr->getID() < s->sr->getID();
}