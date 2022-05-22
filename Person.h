#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;


class Person {

    public:

        Person();
        ~Person();
        string name;
        int id;
        string level;

        bool operator == (Person &person);
        bool operator != (Person &person);
        bool operator > (Person &person);
        bool operator < (Person &person);

};

#endif