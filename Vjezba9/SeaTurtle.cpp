#include "SeaTurtle.h"
#include <stdexcept>

using namespace std;

SeaTurtle::SeaTurtle(const string& n, int a, double w)
    : Animal(n,a,w), Aquatic(n,a,w,200.0){}

string SeaTurtle::getSpecies() const {return "Sea Turtle";}
string SeaTurtle::getName() const {return name;}

double SeaTurtle::getDailyFood() const{
    double food = weight * 0.03;
    if(food==0){
        throw logic_error("Hrana ne moze biti 0!");
    }
    return food;
}
