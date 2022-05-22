#include "Person.h"

Person::Person(){}
Person::~Person(){}

bool Person::operator == (Person &person){

    return id == person.id;
}

bool Person::operator != (Person &person){

    return id != person.id;
}

bool Person::operator > (Person &person){

    return id > person.id;
}

bool Person::operator < (Person &person){

    return id < person.id;
}