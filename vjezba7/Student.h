#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Course.h"
using namespace std;

class Student{
private:
    int id;
    string name;
    string study_program;
    int year;
    Course* enrolled_courses;
    size_t enrolled_count;
    Course* completed_courses;
    size_t completed_count;
    static int total_students;
    void cpyfrm(const Student&);
    void mvfrm(Student&);
public:
    Student(int id, string n, string sp, int y=1);
    Student(const Student&);
    Student(Student&&) noexcept;
    Student& operator=(const Student&);
    Student& operator=(Student&&) noexcept;
    ~Student();

    static int get_total_students();
    int total_ects() const;

    Student& operator+=(const Course&);
    Student& operator++();
    Student operator++(int);

    friend class StudentOffice;
    friend ostream& operator<<(ostream&, const Student&);
    friend istream& operator>>(istream&, Student&);
};

#endif
