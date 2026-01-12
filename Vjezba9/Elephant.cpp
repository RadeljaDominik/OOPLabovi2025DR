#include "Elephant.h"
#include <stdexcept>

using namespace std;

Elephant::Elephant(const string& n, int a, double w)
    : Animal(n,a,w), Mammal(n,a,w,false){}

string Elephant::getSpecies() const {return "Elephant";}
string Elephant::getName() const {return name;}

double Elephant::getDailyFood() const{
    double food = weight * 0.04;
    if (food == 0){
        throw logic_error("Hrana ne moze biti 0!");
    }
    return food;
}
