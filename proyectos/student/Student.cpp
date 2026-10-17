#include "Student.h"

#include <iostream>
using namespace std;

void Student::setName(string name){
    this->name = name;
};

void Student::setGrade(float grade){
    this->grade = grade;
};

bool Student::hasPassed(){
    if(grade < 7){
        return false;
    } 
    return true;
}

string Student::getName(){
    return this->name;
}

float Student::getGrade(){
    return this->grade;
}

