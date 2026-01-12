#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Mammal.h"
using namespace std;

class Elephant : public Mamma{
public:
    Elephant(const string&, int, double);
    string getSpecies() const override;
    string getName() const, override;
    double getDailyFood() const override;
};


#endif // ELEPHANT_H
