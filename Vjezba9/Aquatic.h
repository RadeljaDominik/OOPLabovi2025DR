#ifndef AQUATIC_H
#define AQUATIC_H
#include "Animal.h"
using namespace std;
class Aquatic : public Animal {
private:
    double maxDiveDepth;
public:
    Aquatic(const string& name, int age, double weight, double maxDiveDepth);

};
#endif // AQUATIC_H
