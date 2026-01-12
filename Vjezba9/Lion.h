#ifndef LION_H
#define LION_H

using namespace std;

#include "Mammal.h"

class Lion : public Mammal{
public:
    Lion(const string& name, int age, double weight);

    string getSpecies() const override;
    string getName() const override;
    double getDailyFood() const override;
};

#endif // LION_H
