#include "Course.h"
using namespace std;

Course::Course(string n, string c, int e)
    :name(n),code(c),ects(e){}

int Course::getECTS() const{
    return ects;
}

string Course::getCode() const{
    return code;
}

ostream& operator<<(ostream& os,const Course& c){
    os << c.name << "("<<c.code<<"); ECTS: "<<c.ects;
    return os;
}

istream& operator>>(istream& is, Course& c){
    is >> c.name >> c.code >> c.ects;
    return is;
}
