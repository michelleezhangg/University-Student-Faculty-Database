#include "FacultyRecords.h"

FacultyRecords::FacultyRecords(){

    facultyID = -1;
    facultyName = "";
    facultyLevel = "";
    facultyDepartment = "";

    facultyAdviseeIDs = new vector<int>();
}

FacultyRecords::FacultyRecords(string fName, int fID, string fLevel, string fDepartment, vector<int> *fAIDs){

    facultyID = fID;
    facultyName = fName;
    facultyLevel = fLevel;
    facultyDepartment = fDepartment;

    facultyAdviseeIDs = new vector<int>();
    
}

FacultyRecords::~FacultyRecords(){}

int FacultyRecords::getFacultyID(){

    return facultyID;
}

vector<int> FacultyRecords::getFacultyAdviseeIDs(){

    return *facultyAdviseeIDs;
}

string FacultyRecords::getFacultyName(){

    return facultyName;
}

string FacultyRecords::getFacultyLevel(){

    return facultyLevel;
}

string FacultyRecords::getFacultyDepartment(){

    return facultyDepartment;
}

void FacultyRecords::setFacultyID(int fID){

    facultyID = fID;
}

void FacultyRecords::setFacultyAdviseeIDs(vector<int> *fAdviseeIDs){

    facultyAdviseeIDs = fAdviseeIDs;
}

void FacultyRecords::setFacultyName(string fName){

    facultyName = fName;
}

void FacultyRecords::setFacultyLevel(string fLevel){

    facultyLevel = fLevel;
}

void FacultyRecords::setFacultyDepartment(string fDepartment){

    facultyDepartment = fDepartment;
}