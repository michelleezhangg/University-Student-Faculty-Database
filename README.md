# CPSC350_SP22_ASSIGNMENT6_ZHANG

## Identifying Information

* Names: Michelle Zhang, Sanil Doshi
* Student IDs: 2380210, 2344493
* Emails: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees

## Source Files

* BST.h
* Database.cpp
* Database.h
* Faculty.cpp
* Faculty.h
* FacultyRecords.cpp
* FacultyRecords.h
* GenStack.h
* LinkedList.h
* main.cpp
* Person.cpp
* Person.h
* RollBack.cpp
* RollBack.h
* Serialization.cpp
* Serialization.h
* Student.cpp
* Student.h
* StudentRecords.cpp
* StudentRecords.h

* README.md
* Makefile

## References

* overloading operator << in the classes Student and Faculty.
    * https://stackoverflow.com/questions/53211020/making-my-own-tostring-method-on-c-struct
* removing an item from a vector
    * https://www.cplusplus.com/reference/vector/vector/erase/ 
* ios_base::app
    * https://en.cppreference.com/w/cpp/io/ios_base/openmode


## Known Errors

* N/A

## Build Instructions

* make all

## Build Design

* This database is implemented with at most 1000 students and 1000 faculty members. When an ID is randomized in the program, it should lie in the range 1-1000 for both students and faculty members.
* At least one faculty member must be added before adding a student because a student needs to be initialized with an advisor. The program will inform the user to do this.
* When a new student is added, the advisor/faculty ID is prompted.
* When a new faculty is added, they have no student advisees.