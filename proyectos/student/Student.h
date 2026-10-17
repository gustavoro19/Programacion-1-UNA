#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student {
    private:  
        int id;
        string name;
        float grade;
    public:
       void setName(string name);
       void setGrade(float grade);
       bool hasPassed();
       string getName();
       float getGrade();
};
#endif