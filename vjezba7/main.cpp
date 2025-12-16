#include <iostream>
#include <vector>
#include "Student.h"
#include "StudentOffice.h"
#include "UniversityConstants.h"

using namespace std;

int main(){
    vector<Student> students;
    students.emplace_back(1,"Ana","Racunarstvo");
    students.emplace_back(2,"Ivan","Elektronika");

    UniversityConstants::print_university_rules();

    Course c1("OOP","SRC119",7);
    Course c2("SPA","SRC115",6);
    Course c3("LinA","SRC101",5);

    StudentOffice::enroll_student(students[0],c1);
    StudentOffice::enroll_student(students[1],c3);
    StudentOffice::enroll_student(students[0],c2);

    StudentOffice::update_student_years(students);

    for(const auto& s : students){
        cout<<s<<endl;
    }

    cout<<"Total students: "<<Student::get_total_students()<<endl;

    return 0;
}
