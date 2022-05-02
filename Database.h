#ifndef DATABASE_H
#define  DATABASE_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"

class Database {
    public:
        Database(); // default constructor
        ~Database(); // destructor

        void run(); // core function

        // auxiliary functions
        int printMenu();
        void printAllStudents();
        void printAllFaculty();
        void printStudentInfo();
        void printFacultyInfo();
        void printFacultyInfoFromStudent();
        void printFacultyAdviseesInfo();
        void addNewStudent();
        void deleteStudent();
        void addNewFaculty();
        void deleteFaculty();
        void changeStudentAdvisors();
        void removeFacultyAdvisees();
        void undo();
        
    private:
        BST<Student> *masterStudent;
        BST<Faculty> *masterFaculty;
};

#endif