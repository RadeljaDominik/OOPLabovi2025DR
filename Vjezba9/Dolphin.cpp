#include "Dolphin.h"
#include <stdexcept>
using namespace std;

Dolphin::Dolphin(const string& n,int a, double w)
    : Animal(n,a,w), Mammal(n,a,w,true), Aquatic(n,a,w,300.0) {}

string Dolphin::getSpecies() const {return "Dolphin";}
string Dolphin::getName() const {return name;}

double Dolphin::getDailyFood() const{
    double food = weight * 0.05;
    if(food == 0){
        throw logic_error("Hrana ne moze biti 0!");
    }
    return food;
}
