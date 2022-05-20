# CPSC350_SP22_ASSIGNMENT6_ZHANG

## Identifying Information

* Name: Michelle Zhang
* Student ID: 2380210
* Email: mizhang@chapman.edu
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

## Known Errors

* N/A

## Build Instructions

* make all

## Build Design

* This database is implemented with at most 10000 students and 10000 faculty members. When an ID is randomized in the program, it should lie in the range 1-10000 for both students and faculty members.
    * The IDs are randomize when adding in a new student or faculty member.
