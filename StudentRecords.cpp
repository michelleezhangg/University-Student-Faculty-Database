#include "StudentRecords.h"

StudentRecords::StudentRecords(){

    studentName = "";
    studentID = -1;
    studentLevel = "";
    studentMajor = "";
    studentGPA = 0.0;
    studentAdvisorID = -1;
}

StudentRecords::StudentRecords(string sName, int sID, string sLevel, string sMajor, double sGPA, int sAdvisorID){

    studentName = sName;
    studentID = sID;
    studentLevel = sLevel;
    studentMajor = sMajor;
    studentGPA = sGPA;
    studentAdvisorID = sAdvisorID;
 
}

StudentRecords::~StudentRecords(){}

int StudentRecords::getStudentID(){

    return studentID;
}

int StudentRecords::getStudentAdvisorID(){

    return studentAdvisorID;
}

double StudentRecords::getStudentGPA(){

    return studentGPA;
}

string StudentRecords::getStudentLevel(){

    return studentLevel;
}

string StudentRecords::getStudentMajor(){

    return studentMajor;
}

void StudentRecords::setStudentID(int sID){

    studentID = sID;
}

void StudentRecords::setStudentAdvisorID(int sAdvisorID){

    studentAdvisorID = sAdvisorID;
}

void StudentRecords::setStudentGPA(double sGPA){

    studentGPA = sGPA;
}

void StudentRecords::setStudentLevel(string sLevel){

    studentLevel = sLevel;
}

void StudentRecords::setStudentMajor(string sMajor){

    studentMajor = sMajor;
}