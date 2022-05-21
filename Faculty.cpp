#include "Faculty.h"

Faculty::Faculty(){

    numAdvisees = 0;
    department = "";
    adviseeIDs = new vector<int>();
    facultyRecord = new FacultyRecords();
}

Faculty::Faculty(string fName, int fID, string fLevel, string fDepartment){

    name = fName;
    id = fID;
    level = fLevel;
    department = fDepartment;
    adviseeIDs = new vector<int>();
    facultyRecord = new FacultyRecords(fName, fID, fLevel, fDepartment, adviseeIDs);
}

Faculty::~Faculty(){}

string Faculty::getName(){

    return name;
}

int Faculty::getID(){

    return id;
}

string Faculty::getLevel(){

    return level;
}

string Faculty::getDepartment(){

    return department;
}

vector<int> Faculty::getAdviseeIDs(){

    return *adviseeIDs;
}

void Faculty::setName(string fName){

    name = fName;
}
void Faculty::setID(int fID){

    id = fID;
}
void Faculty::setLevel(string fLevel){

    level = fLevel;
}
void Faculty::setDepartment(string fDepartment){

    department = fDepartment;
}
void Faculty::setAdviseeID(vector<int> *aIDs){

    adviseeIDs = aIDs;
}

void Faculty::addAdvisee(int id){

    adviseeIDs->push_back(id);
    numAdvisees++;
}

void Faculty::removeAdvisee(int id){

    for(int i = 0; i < adviseeIDs->size(); i++) {

        if(adviseeIDs->at(i) == id){

            adviseeIDs->erase(adviseeIDs->begin()+i);
        }
    }
}

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

ostream& operator << (ostream &os, const Faculty &f) {
    os << "FACULTY INFORMATION:" << "\n";
    os << endl << "ID: " << f.id << "\n";
    os << "Name: " << f.name << "\n";
    os << "Level: " << f.level << "\n";
    os << "Department: " << f.department << "\n";
    os << "Advisees IDs: " << endl;

    for (int i = 0; i < f.adviseeIDs->size(); ++i) {
        if (i == f.adviseeIDs->size() - 1)
            os << f.adviseeIDs->at(i) << "\n";
        else
            os << f.adviseeIDs->at(i) << ", ";
    }

    return os;
}



