#include "Mammal.h"
using namespace std;
Mammal::Mammal(const string& n,int a, double w,bool hF)
    :Animal(n,a,w),hasFur(hF){
        if(hasFur==true){
            cout<<"Stvoren sisavac s dlakom"<<endl;
        }else{
            cout<<"Stvoren sisavac bez dlake"<<endl;
        }
    }



