#ifndef DB_H
#define DB_H

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "Serialization.h"
#include "RollBack.h"

class DB{

    public:

        DB();
        ~DB();

        void simulate();
        int printOptions();

        void printAllStudentInfo(); //prints all student info
        void printAllFacultyInfo();
        void printSpecificStudent();
        void printSpecificFaculty();
        void printFacultyAdvisor();
        void printFacultyAdvisees();
        void addNewStudent();
        void deleteStudent();
        void addNewFaculty();
        void deleteFaculty();
        void changeStudentAdvisor();
        void removeAdvisee();
        void Undo();
        void Exit();





    private:

        BST<Student> *masterStudent;
        BST<Faculty> *masterFaculty;

        RollBack *rb;
        Serialization *s;



};

#endif