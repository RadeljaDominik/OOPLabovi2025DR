#include "Student.h"
#include "UniversityConstants.h"
using namespace std;

int Student::total_students=0;

Student::Student(int i, string n, string sp, int y)
    : id(i),name(n),study_program(sp),year(y),enrolled_courses(nullptr),enrolled_count(0),completed_courses(nullptr),completed_count(0)
    {
    total_students++;
    }

Student::Student(const Student& st2){
    cpyfrm(st2);
    total_students++;
}

Student::~Student(){
    delete[] enrolled_courses;
    delete[] completed_courses;
    total_students--;
}

Student& Student::operator=(const Student& st2){
    if(this != &st2){
        delete[] enrolled_courses;
        delete[] completed_courses;
        cpyfrm(st2);
    }
    return *this;
}

Student& Student::operator=(Student&& st2) noexcept {
    if (this != &st2) {
        delete[] enrolled_courses;
        delete[] completed_courses;
        mvfrm(st2);
    }
    return *this;
}

void Student::cpyfrm(const Student& s) {
    id = s.id;
    name = s.name;
    study_program = s.study_program;
    year = s.year;

    enrolled_count = s.enrolled_count;
    completed_count = s.completed_count;

    enrolled_courses = enrolled_count ? new Course[enrolled_count] : nullptr;
    completed_courses = completed_count ? new Course[completed_count] : nullptr;

    for (size_t i = 0; i < enrolled_count; i++)
        enrolled_courses[i] = s.enrolled_courses[i];

    for (size_t i = 0; i < completed_count; i++)
        completed_courses[i] = s.completed_courses[i];
}

void Student::mvfrm(Student& s) {
    id = s.id;
    name = std::move(s.name);
    study_program = std::move(s.study_program);
    year = s.year;

    enrolled_courses = s.enrolled_courses;
    enrolled_count = s.enrolled_count;

    completed_courses = s.completed_courses;
    completed_count = s.completed_count;

    s.enrolled_courses = nullptr;
    s.completed_courses = nullptr;
    s.enrolled_count = s.completed_count = 0;
}


int Student::get_total_students() {
    return total_students;
}


int Student::total_ects() const {
    int sum = 0;
    for (size_t i = 0; i < completed_count; i++)
        sum += completed_courses[i].getECTS();
    return sum;
}


Student& Student::operator+=(const Course& c) {
    Course* tmp = new Course[enrolled_count + 1];
    for (size_t i = 0; i < enrolled_count; i++)
        tmp[i] = enrolled_courses[i];
    tmp[enrolled_count++] = c;

    delete[] enrolled_courses;
    enrolled_courses = tmp;
    return *this;
}

Student& Student::operator++() {
    if (total_ects() >= UniversityConstants::REQUIRED_ECTS_PER_YEAR)
        year++;
    return *this;
}

Student Student::operator++(int) {
    Student old = *this;
    ++(*this);
    return old;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Student " << s.name << " (" << s.id << "), "
       << s.study_program << ", year " << s.year;
    return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
    is >> s.id >> s.name >> s.study_program >> s.year;
    return is;
}
