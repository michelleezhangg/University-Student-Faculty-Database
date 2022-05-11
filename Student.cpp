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
    major = "";
    gpa = 0.0;
    advisorID = -1;
    sr = new StudentRecords(); //FIXME: inheritance
}

Student::Student(int i, string n, string l, string m, double g, int a) { // overloaded constructor
    id = i;
    name = n;
    level = l;
    major = m;
    gpa = g;
    advisorID = a;
    sr = new StudentRecords(id, name, level, major, gpa, advisorID); //FIXME: inheritance
}

Student::~Student() { // destructor
    delete sr;
}

// accessors
/** @return major a string representing the major of the student. */
string Student::getMajor() {
    return major;
}

/** @return gpa a double representing the gpa of the student. */
double Student::getGPA() {
    return gpa;
}

/** @return advisorID an integer representing the advisor's ID of the student. */
int Student::getAdvisorID() {
    return advisorID;
}

/** @return sr a StudentRecords object representing the records of the student. */
StudentRecords Student::getStudentRecords() {
    return *sr;
}

// mutators
/**
 * sets the private member: major.
 * @param m a string representing the major of the student.
 */
void Student::setMajor(string m) {
    major = m;
}

/**
 * sets the private member: gpa.
 * @param g a double representing the gpa of the student.
 */
void Student::setGPA(double g) {
    gpa = g;
}

/**
 * sets the private member: advisorID.
 * @param a an integer representing the advisor's ID of the student.
 */
void Student::setAdvisorID(int a) {
    advisorID = a;
}

/**
 * sets the private member: sr.
 * @param student_records a StudentRecords object representing the records of the student.
 */
void Student::setStudentRecords(StudentRecords *student_records) {
    sr = student_records;
}

// operator overloading
ostream& operator << (ostream &os, const Student &s){
    os << "Student Information" << "\n";
    os << "ID: " << s.id << "\n";
    os << "Name: " << s.name << "\n";
    os << "Level: " << s.level << "\n";
    os << "Major: " << s.major << "\n";
    os << "GPA: " << s.gpa << "\n";
    os << "Advisor ID: " << s.advisorID << "\n";

    return os;
}