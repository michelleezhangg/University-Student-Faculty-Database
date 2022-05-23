/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the StudentRecords class.
*/

#include "StudentRecords.h"

StudentRecords::StudentRecords(){ // default constructor

    studentName = "";
    studentID = -1;
    studentLevel = "";
    studentMajor = "";
    studentGPA = 0.0;
    studentAdvisorID = -1;
}

/**
 * overloaded constructor for the StudentRecords class.
 * @param sName a string representing the name of the student.
 * @param sID an integer representing the ID of the student.
 * @param sLevel a string representing the level of the student.
 * @param sMajor a string representing the major of the student.
 * @param sGPA a double representing the gpa of the student.
 * @param sAdvisor an integer representing the advisor ID of the student.
 */
StudentRecords::StudentRecords(string sName, int sID, string sLevel, string sMajor, double sGPA, int sAdvisorID){ // overloaded constructor

    studentName = sName;
    studentID = sID;
    studentLevel = sLevel;
    studentMajor = sMajor;
    studentGPA = sGPA;
    studentAdvisorID = sAdvisorID;
 
}

StudentRecords::~StudentRecords(){} // destructor

// accessors
/** @return studentUD an integer representing the ID of the student. */
int StudentRecords::getStudentID(){

    return studentID;
}

/** @return studentAdvisorID an integer representing the ID of the student. */
int StudentRecords::getStudentAdvisorID(){

    return studentAdvisorID;
}

/** @return studentGPA a double representing the GPA of the student. */
double StudentRecords::getStudentGPA(){

    return studentGPA;
}

/** @return studentLevel a string representing the level of the student. */
string StudentRecords::getStudentLevel(){

    return studentLevel;
}

/** @return studentMajor a string representing the major of the student. */
string StudentRecords::getStudentMajor(){

    return studentMajor;
}

// mutators
/** 
 * sets the ID of the student.
 * @param sID an integer representing the ID of the student. 
 */
void StudentRecords::setStudentID(int sID){

    studentID = sID;
}

/**
 * sets the advisor ID of the student.
 * @param sAdvisorID an integer representing the ID of the student's advisor (faculty). 
 */
void StudentRecords::setStudentAdvisorID(int sAdvisorID){

    studentAdvisorID = sAdvisorID;
}

/** 
 * sets the GPA of the student.
 * @param sGPA a double representing the GPA of the student. 
 */
void StudentRecords::setStudentGPA(double sGPA){

    studentGPA = sGPA;
}

/** 
 * sets the level of the student.
 * @param sLevel a string representing the level of the student.
 * examples: freshman, sophomore, junior, senior, etc.
 */
void StudentRecords::setStudentLevel(string sLevel){

    studentLevel = sLevel;
}

/**
 * sets the major of the student.
 * @param sMajor a string representing the major of the student.
 */
void StudentRecords::setStudentMajor(string sMajor){

    studentMajor = sMajor;
}
