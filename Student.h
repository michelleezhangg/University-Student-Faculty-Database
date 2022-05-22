#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "StudentRecords.h"

class Student : public Person {

    public:

        Student();
        Student(string name, int id, string level, string major, double gpa, int advisorID);
        ~Student();

        StudentRecords *studentRecord;

        //getters
        string getName();
        int getID();
        string getLevel();
        string getMajor();
        int getGPA();
        int getAdvisorID();

        //setters
        void setName(string sName);
        void setID(int sID);
        void setLevel(string sLevel);
        void setMajor(string sMajor);
        void setGPA(double sGPA);
        void setAdvisorID(int sAdvisorID);

        string getStudentInfo();
        friend ostream& operator << (ostream &os, const Student &s);

        string major;
        double gpa;
        int advisorID;

};

#endif