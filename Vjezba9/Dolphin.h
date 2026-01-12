#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "Mammal.h"
#include "Aquatic.h"
using namespace std;

class Dolphin : public Mammal, public Aquatic {
public:
    Dolphin(const string&, int, double);
    string getSpecies() const override;
    string getName() const override;
    double getDailyFood() const override;
};

#endif // DOLPHIN_H
