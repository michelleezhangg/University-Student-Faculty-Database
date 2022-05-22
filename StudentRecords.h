#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#include <iostream>
#include <string>

using namespace std;

class StudentRecords {

    public:

        StudentRecords();
        StudentRecords(string studentName, int studentID, string studentLevel, string studentMajor, double studentGPA, int studentAdvisorID);
        ~StudentRecords();

        //getters
        string getStudentName();
        int getStudentID();
        string getStudentLevel();
        string getStudentMajor();
        double getStudentGPA();
        int getStudentAdvisorID();

        //setters
        void setStudentName();
        void setStudentID(int sID);
        void setStudentLevel(string sLevel);
        void setStudentMajor(string sMajor);
        void setStudentGPA(double sGPA);
        void setStudentAdvisorID(int sAdvisorID);        

    private:

        string studentName;
        int studentID;
        string studentLevel;
        string studentMajor;
        double studentGPA;
        int studentAdvisorID;

};

#endif