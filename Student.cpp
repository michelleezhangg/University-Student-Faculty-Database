/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Student Class.
*/

#include "Student.h"

Student::Student(){ // default constructor

    major = "";
    gpa = 0.0;
    advisorID = -1;
    studentRecord = new StudentRecords();
}

/**
 * overloaded constructor for the Student class.
 * @param sName a string representing the name of the student.
 * @param sID an integer representing the ID of the student.
 * @param sLevel a string representing the level of the student.
 * @param sMajor a string representing the major of the student.
 * @param sGPA a double representing the gpa of the student.
 * @param sAdvisorID an integer representing the advisor ID of the student.
 */
Student::Student(string sName, int sID, string sLevel, string sMajor, double sGPA, int sAdvisorID){ // overloaded constructor

    name = sName;
    id = sID;
    level = sLevel;
    major = sMajor;
    gpa = sGPA;
    advisorID = sAdvisorID;
    studentRecord = new StudentRecords(sName, sID, sLevel, sMajor, sGPA, sAdvisorID);
}

Student::~Student(){ // destructor
    delete studentRecord;
}

// accessors
/** @return name a string representing the name of the student. */
string Student::getName(){

    return name;
}

/** @return id an integer representing the ID of the student. */
int Student::getID(){

    return id;
}

/** @return level a string representing the level of the student. */
string Student::getLevel(){

    return level;
}

/** @return major a string representing the major of the student. */
string Student::getMajor(){

    return major;
}

/** @return gpa a double representing the GPA of the student. */
int Student::getGPA(){

    return gpa;
}

/** @return advisorID an integer representing the advisor ID of the student. */
int Student::getAdvisorID(){

    return advisorID;
}

// mutators
/**
 * sets the name of the student.
 * @param sName a string representing the name of the student.
 */
void Student::setName(string sName){

    name = sName;
}

/**
 * sets the ID of the student.
 * @param sID an integer representing the ID of the student.
 */
void Student::setID(int sID){

    id = sID;
}

/**
 * sets the level of the student.
 * @param sLevel a string representing the level of the student.
 */
void Student::setLevel(string sLevel){

    level = sLevel;
}

/**
 * sets the major of the student.
 * @param sMajor a string representing the major of the student.
 */
void Student::setMajor(string sMajor){

    major = sMajor;
}

/**
 * sets the GPA of the student.
 * @param sGPA a double representing the GPA of the student.
 */
void Student::setGPA(double sGPA){

    gpa = sGPA;
}

/**
 * sets the advisor ID of the student.
 * @param sAdvisorID a string representing the advisor ID of the student.
 */
void Student::setAdvisorID(int sAdvisorID){

    advisorID = sAdvisorID;
}

/**
 * gets the student's information in the form of a string.
 * @return student_info a string representing the student's information.
 */
string Student::getStudentInfo() {
    string student_info = "";

    student_info += "Student Information\n";
    student_info += "ID: " + to_string(id) + "\n";
    student_info += "Name: " + name + "\n";
    student_info += "Level: " + level + "\n";
    student_info += "Major: " + major + "\n";
    student_info += "GPA:" + to_string(gpa) + "\n";
    student_info += "Advisor ID: " + to_string(advisorID) + "\n";

    return student_info;
}

/**
 * overloads the operator << for a Student object.
 * @param s a Student object we wish to retrieve information from.
 */
ostream& operator << (ostream &os, const Student &s){
    os << endl << "STUDENT INFORMATION:" << "\n";
    os << "ID: " << s.id << "\n";
    os << "NAME: " << s.name << "\n";
    os << "LEVEL: " << s.level << "\n";
    os << "MAJOR: " << s.major << "\n";
    os << "GPA: " << s.gpa << "\n";
    os << "ADVISOR ID: " << s.advisorID << "\n";

    return os;
}

