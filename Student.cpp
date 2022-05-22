#include "Student.h"

Student::Student(){

    major = "";
    gpa = 0.0;
    advisorID = -1;
    studentRecord = new StudentRecords();
}

Student::Student(string sName, int sID, string sLevel, string sMajor, double sGPA, int sAdvisorID){

    name = sName;
    id = sID;
    level = sLevel;
    major = sMajor;
    gpa = sGPA;
    advisorID = sAdvisorID;
    studentRecord = new StudentRecords(sName, sID, sLevel, sMajor, sGPA, sAdvisorID);
}

Student::~Student(){}

//getters
string Student::getName(){

    return name;
}

int Student::getID(){

    return id;
}

string Student::getLevel(){

    return level;
}
string Student::getMajor(){

    return major;
}
int Student::getGPA(){

    return gpa;
}
int Student::getAdvisorID(){

    return advisorID;
}

//setters
void Student::setName(string sName){

    name = sName;
}

void Student::setID(int sID){

    id = sID;
}

void Student::setLevel(string sLevel){

    level = sLevel;
}
void Student::setMajor(string sMajor){

    major = sMajor;
}
void Student::setGPA(double sGPA){

    gpa = sGPA;
}
void Student::setAdvisorID(int sAdvisorID){

    advisorID = sAdvisorID;
}

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

