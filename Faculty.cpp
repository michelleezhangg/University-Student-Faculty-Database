/*
* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Chapman Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

* This is the implementation file for the Faculty Class.
* This class inherits from Person Class.
*/

#include "Faculty.h"

Faculty::Faculty(){ // default constructor

    numAdvisees = 0;
    department = "";
    adviseeIDs = new vector<int>();
    facultyRecord = new FacultyRecords();
}

/**
 * overloaded constructor for the Faculty class.
 * @param fName a string representing the name of the faculty.
 * @param fID an integer representing the ID of the faculty.
 * @param fLevel a string representing the level of the faculty.
 * @param fDepartment a string representing the department of the faculty.
 */
Faculty::Faculty(string fName, int fID, string fLevel, string fDepartment){ // overloaded constructor

    name = fName;
    id = fID;
    level = fLevel;
    department = fDepartment;
    adviseeIDs = new vector<int>();
    facultyRecord = new FacultyRecords(fName, fID, fLevel, fDepartment, adviseeIDs);
}

Faculty::~Faculty(){ // destructor
    delete facultyRecord;
    delete adviseeIDs;
}

// accessors
/** @return name a string representing the name of the faculty member. */
string Faculty::getName(){

    return name;
}

/** @return id an integer representing the ID of the faculty member. */
int Faculty::getID(){

    return id;
}

/** @return level a string representing the level of the faculty member. */
string Faculty::getLevel(){

    return level;
}

/** @return department a string representing the department of the faculty member. */
string Faculty::getDepartment(){

    return department;
}

/** @return adviseeIDs a vector storing the advisee IDs of this faculty member. */
vector<int> Faculty::getAdviseeIDs(){

    return *adviseeIDs;
}

// mutators
/**
 * sets the name of the faculty member.
 * @param fName a string representing the name of the faculty member.
 */
void Faculty::setName(string fName){

    name = fName;
}

/**
 * sets the ID of the faculty member.
 * @param fID an integer representing the ID of the faculty member.
 */
void Faculty::setID(int fID){

    id = fID;
}

/**
 * sets the level of the faculty member.
 * @param fLevel a string representing the level of the faculty member.
 */
void Faculty::setLevel(string fLevel){

    level = fLevel;
}

/**
 * sets the department of the faculty member.
 * @param fDepartment a string representing the department of the faculty member.
 */
void Faculty::setDepartment(string fDepartment){

    department = fDepartment;
}

/**
 * sets the advisee ID vector of the faculty member.
 * @param aIDs a vector storing the advisee IDs of the faculty member.
 */
void Faculty::setAdviseeID(vector<int> *aIDs){

    adviseeIDs = aIDs;
}

/**
 * adds an advisee ID to the vector of student IDs.
 * @param id an integer representing the ID to add.
 */
void Faculty::addAdvisee(int id){

    adviseeIDs->push_back(id);
    numAdvisees++;
}

/**
 * removes an advisee ID from the vector of student IDs.
 * @param id an integer representing the ID to remove.
 */
void Faculty::removeAdvisee(int id){

    for(int i = 0; i < adviseeIDs->size(); i++) {

        if(adviseeIDs->at(i) == id){

            adviseeIDs->erase(adviseeIDs->begin()+i);
            numAdvisees--;
        }
    }
}

/**
 * returns all of the faculty member's advisees.
 * handles the case when the faculty member has no advisees.
 * @return advisees a string representing the faculty member's advisees.
 */
string Faculty::getAdviseeID() {

    string advisee = "";

    if (adviseeIDs->size() == 0)
        return "This faculty member has no advisees.";

    else {
        advisee += "Advisees IDs: \n";

        for (int i = 0; i < adviseeIDs->size(); ++i) {
            if (i == adviseeIDs->size() - 1)
                advisee += to_string(adviseeIDs->at(i)) + "\n";
            else
                advisee += to_string(adviseeIDs->at(i)) + ", ";
        }
    }

    return advisee;
}

/**
 * gets the faculty member's information in the form of a string.
 * @return faculty_info a string representing the faculty member's information.
 */
string Faculty::getFacultyInfo(){

    string faculty_info = "";

    faculty_info += "Faculty Information\n";
    faculty_info += "ID: " + to_string(id) + "\n";
    faculty_info += "Name: " + name + "\n";
    faculty_info += "Level: " + level + "\n";
    faculty_info += "Department: " + department + "\n";
    faculty_info += getAdviseeID();

    return faculty_info;
    
}

/**
 * overloads the operator << for a Faculty object.
 * @param f a Faculty object we wish to retrieve information from.
 */
ostream& operator << (ostream &os, const Faculty &f) {
    os << endl << "FACULTY INFORMATION:" << "\n";
    os << "NAME: " << f.name << "\n";
    os << "ID: " << f.id << "\n";
    os << "LEVEL: " << f.level << "\n";
    os << "DEPARTMENT: " << f.department << "\n";
    os << "ADVISEE IDs: " << endl;

    for (int i = 0; i < f.adviseeIDs->size(); ++i) {
        if (i == f.adviseeIDs->size() - 1)
            os << f.adviseeIDs->at(i) << "\n";
        else
            os << f.adviseeIDs->at(i) << ", ";
    }

    return os;
}



