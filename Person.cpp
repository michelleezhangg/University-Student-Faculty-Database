/*
* Name: Michelle Zhang
* Student ID: 2380210
* Chapman Email: mizhang@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Person class.
* This is the base class for the Student Class and the Faculty Class.
*/

#include "Person.h"

Person::Person() { // default constructor
    name = "";
    id = -1;
    level = "";
}

Person::~Person() {} // destructor

/**
 * overloads the operator == for the Person class.
 * @param &p a Person to compare with operator ==
 * @return true if the persons are equal (their IDs are equal).
 * @return false if the persons are not equal (their IDs are not equal).
 */
bool Person::operator == (Person &p) {
    return id == p.id;
}

/**
 * overloads the operator != for the Person class.
 * @param &p a Person to compare with operator !=
 * @return true if the persons are not equal (their IDs are not equal).
 * @return false if the persons are equal (their IDs are equal).
 */
bool Person::operator != (Person &p) {
    return id != p.id;
}

/**
 * overloads the operator > for the Person class.
 * @param &p a Person to compare with operator >
 * @return true if the left person is greater than the right person (left person's ID > right person's ID).
 * @return false if the left person is not greater than the right person.
 */
bool Person::operator > (Person &p) {
    return id > p.id;
}

/**
 * overloads the operator < for the Person class.
 * @param &p a Person to compare with operator <
 * @return true if the left person is less than the right person (left person's ID < right person's ID).
 * @return false if the left person is not less than the right person.
 */
bool Person::operator < (Person &p) {
    return id < p.id;
}