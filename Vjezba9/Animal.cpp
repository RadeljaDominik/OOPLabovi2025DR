#include "Animal.h"
using namespace std;
Animal::Animal(const string n, int a, double w)
    :name(n),age(a),weight(w)
    {
        if(name.empty()){
            throw invalid_argument("Ime ne moze biti prazno!");
        }
        if(age < 0){
            throw invalid_argument("Dob ne moze biti manja od 0!");
        }
        if(weight<=9){
            throw invalid_argument("Tezina ne moze biti manja ili jednaka 0!");
        }
    }
