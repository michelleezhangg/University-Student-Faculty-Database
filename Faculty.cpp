/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Faculty Class.
*/

#include "Faculty.h"

Faculty::Faculty() { // default constructor
    fr = new FacultyRecords();
}

Faculty::~Faculty() { // destructor
    delete fr;
}

// overloaded operator
/**
 * overloads the operator == for the Faculty class.
 * @param f a Faculty to compare with operator ==
 * @return true if the faculty members are equal (their IDs are equal).
 * @return false if the faculty members are not equal (their IDs are not equal).
 */
bool Faculty::operator == (Faculty *f) {
    return this->fr->getID() == f->fr->getID();
}

/**
 * overloads the operator != for the Student class.
 * @param f a Faculty to compare with operator !=
 * @return true if the faculty members are not equal (their IDs are not equal).
 * @return false if the faculty members are equal (their IDs are equal).
 */
bool Faculty::operator != (Faculty *f) {
    return this->fr->getID() != f->fr->getID();
}

/**
 * overloads the operator > for the Faculty class.
 * @param f a Faculty to compare with operator >
 * @return true if the left faculty member is greater than the right faculty member (left faculty ID > right faculty ID).
 * @return false if the left faculty member is not greater than the right faculty member.
 */
bool Faculty::operator > (Faculty *f) {
    return this->fr->getID() > f->fr->getID();
}

/**
 * overloads the operator < for the Faculty class.
 * @param f a Faculty to compare with operator <
 * @return true if the left faculty member is less than the right faculty member (left faculty ID < right faculty ID).
 * @return false if the left faculty member is not less than the right faculty member.
 */
bool Faculty::operator < (Faculty *f) {
    return this->fr->getID() < f->fr->getID();
}