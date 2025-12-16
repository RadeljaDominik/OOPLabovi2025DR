#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course{
private:
    string name;
    string code;
    int ects;
public:
    Course(string n="",string c="",int e=5);
    int getECTS() const;
    string getCode() const;

    friend ostream& operator<<(ostream&, const Course&);
    friend istream& operator>>(istream&, Course&);
};

#endif
