#include "Person.h"

Person::Person() { // default constructor
    name = "";
    id = -1;
    level = "";
}

Person::~Person() {} // destructor

// accessors
/** @return id an integer representing the ID of the person. */
int Person::getID() {
    return id;
}

/** @return name a string representing the name of the person. */
string Person::getName() {
    return name;
}

/** @return level a string representing the level of the person. */
string Person::getLevel() {
    return level;
}

// mutators
/**
 * sets the private member: id.
 * @param i an integer representing the id of the person.
 */
void Person::setID(int i) {
    id = i;
}

/**
 * sets the private member: name.
 * @param n a string representing the name of the person.
 */
void Person::setName(string n) {
    name = n;
}

/**
 * sets the private member: level.
 * @param l a string representing the level of the person.
 */
void Person::setLevel(string l) {
    level = l;
}

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