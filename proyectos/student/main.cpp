#include <iostream>
#include "Student.h"

using namespace std;

int main()
{

    Student student1;
    student1.setName("Gustavo");
    student1.setGrade(8.5);
    if (student1.hasPassed())
    {
        cout << student1.getName() << "tuvo la calificacion: " << student1.getGrade() << endl;
        cout << "APROBADO" << endl;
    }else{
        cout << student1.getName() << "tuvo la calificacion: " << student1.getGrade() << endl;
        cout << "REPROBADO" << endl;
    }
    return 0;
}
