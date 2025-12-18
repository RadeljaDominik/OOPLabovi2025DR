#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Animal{
protected:
    string name;
    int age;
    double weight;
public:
    Animal(const string& name, int age, double weight);
    virtual ~Animal();
    virtual string getSpecies() const = 0;
    virtual double getDailyFood() const = 0;
    virtual string getName() const = 0;
};
#endif // ANIMAL_H
