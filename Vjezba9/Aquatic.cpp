#include "Aquatic.h"
using namespace std;

Aquatic::Aquatic(const string& n, int a, double w, double mD)
    :Animal(n,a,w),maxDiveDepth(mD){
        cout<<"Stvorena vodena zivotinja koja roni do "<<mD<<"m"<<endl;
    }

