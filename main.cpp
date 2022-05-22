/*
* Names: Michelle Zhang, Sanil Doshi
* Student ID: 2380210, 2344493
* Chapman Email: mizhang@chapman.edu, sdoshi@chapman.edu
* Course: CPSC 350-01
* Assignment: Assignment 6 - Building a Database with Binary Search Trees
*/

#include "DB.h"
#include "Serialization.h"

int main(int argc, char** argv){

    DB *database = new DB();

    database->simulate();

    delete database;
    return 0;
}
