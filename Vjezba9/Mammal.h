#ifndef MAMMAL_H
#define MAMMAL_H
using namespace std;
class Mammal : public Animal{
private:
    bool hasFur;
public:
    Mammal(const string& name, int age, double weight, bool hasFur);

};
#endif // MAMMAL_H
