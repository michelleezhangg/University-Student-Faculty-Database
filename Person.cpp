/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Person class.
* This is the base class for the Student Class and the Faculty Class.
*/

#include "Person.h"

Person::Person() {} // default constructor

Person::~Person() {} // destructor

/**
 * overloads the operator == for the Person class.
 * @param &p a Person to compare with operator ==
 * @return true if the persons' IDs are equal and false otherwise.
 */
bool Person::operator == (Person &p) {
    return id == p.id;
}

/**
 * overloads the operator != for the Person class.
 * @param &p a Person to compare with operator !=
 * @return true if the persons' IDs are not equal and false otherwise.
 */
bool Person::operator != (Person &p) {
    return id != p.id;
}

/**
 * overloads the operator > for the Person class.
 * @param &p a Person to compare with operator >
 * @return true if the left person's ID is greater than the right person's and false otherwise.
 */
bool Person::operator > (Person &p) {
    return id > p.id;
}

/**
 * overloads the operator < for the Person class.
 * @param &p a Person to compare with operator <
 * @return true if the left person's ID is less than the right person's and false otherwise.
 */
bool Person::operator < (Person &p) {
    return id < p.id;
}