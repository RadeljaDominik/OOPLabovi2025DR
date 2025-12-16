#ifndef STUDENT_OFFICE_H
#define STUDENT_OFFICE_H

#include <vector>
#include "Student.h"

class StudentOffice {
public:
    static void moveStudent(Student&, std::string);
    static void enroll_student(Student&, const Course&);
    static void process_exam_results(Student&, const Course&);
    static void update_student_years(std::vector<Student>&);
};

#endif
