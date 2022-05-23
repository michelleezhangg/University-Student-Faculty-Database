/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the FacultyRecords class.
*/

#include "FacultyRecords.h"

FacultyRecords::FacultyRecords(){ // default constructor

    facultyID = -1;
    facultyName = "";
    facultyLevel = "";
    facultyDepartment = "";

    facultyAdviseeIDs = new vector<int>();
}

/**
 * overloaded constructor for the Faculty class.
 * @param fName a string representing the name of the faculty.
 * @param fID an integer representing the ID of the faculty.
 * @param fLevel a string representing the level of the faculty.
 * @param fDepartment a string representing the department of the faculty.
 * @param fAIDs a vector storing the advisee IDs of the faculty.
 */
FacultyRecords::FacultyRecords(string fName, int fID, string fLevel, string fDepartment, vector<int> *fAIDs){ // overloaded constructor

    facultyID = fID;
    facultyName = fName;
    facultyLevel = fLevel;
    facultyDepartment = fDepartment;
    facultyAdviseeIDs = new vector<int>();
    
}

FacultyRecords::~FacultyRecords(){ // destructor
    delete facultyAdviseeIDs;
}

// accessors
/** @return facultyID an integer representing the ID of the faculty member. */
int FacultyRecords::getFacultyID(){

    return facultyID;
}

/** @return facultyAdviseeIDs a vector representing the collection of the faculty's students' IDs. */
vector<int> FacultyRecords::getFacultyAdviseeIDs(){

    return *facultyAdviseeIDs;
}

/** @return facultyName a string representing the name of the faculty member. */
string FacultyRecords::getFacultyName(){

    return facultyName;
}

/** 
 * @return facultyLevel a string representing the level of the faculty member.
 * examples: lecturer, assistant professor, associate professor, etc.
 */
string FacultyRecords::getFacultyLevel(){

    return facultyLevel;
}

/** @return facultyDepartment a string representing the department of the faculty member. */
string FacultyRecords::getFacultyDepartment(){

    return facultyDepartment;
}

// mutators
/**
 * sets the faculty's ID.
 * @param fID an integer representing the ID of the faculty member. 
 */
void FacultyRecords::setFacultyID(int fID){

    facultyID = fID;
}


void FacultyRecords::setFacultyAdviseeIDs(vector<int> *fAdviseeIDs){

    facultyAdviseeIDs = fAdviseeIDs;
}

/**
 * sets the faculty's name.
 * @param fName a string representing the name of the faculty member. 
 */
void FacultyRecords::setFacultyName(string fName){

    facultyName = fName;
}

/**
 * sets the faculty's level.
 * @param fLevel a string representing the level of the faculty member. 
 * examples: lecturer, assistant professor, associate professor, etc.
 */
void FacultyRecords::setFacultyLevel(string fLevel){

    facultyLevel = fLevel;
}

/**
 * sets the faculty's department
 * @param fDepartment a string representing the department of the faculty member. 
 */
void FacultyRecords::setFacultyDepartment(string fDepartment){

    facultyDepartment = fDepartment;
}
