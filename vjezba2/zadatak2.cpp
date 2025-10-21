#include <iostream>
#include "zadatak2.h"

using namespace std;

vctr* vector_new(size_t in){
    vctr* v = new vctr;
    v->el = new int[in];
    v->logVel = 0;
    v->fizVel = in;

    return v;
}

void vector_delete(vctr* v){
    delete v->el;
    delete v;
}

void vector_push_back(vctr* v, int vr){
    if(v->logVel >= v->fizVel){
        size_t nVel = v->fizVel*2;
        int* nEl = new int[nVel];

        for(size_t i = 0; i < v->logVel; i++){
            nEl[i] = v->el[i];
        }
        delete v->el;
        v->el = nEl;
        v->fizVel = nVel;
    }
    v->el[v->logVel] = vr;
    v->logVel++;
}

void vector_pop_back(vctr* v){
    if(v->logVel == 0){
        cout<<"Vektor je prazan!"<<endl;
        return;
    }
    v->logVel--;
}

int vector_front(vctr* v){
    if(v->logVel==0){
        cout<<"Vektor je prazan!"<<endl;
        return NULL;
    }
    return v->el[0];
}

int vector_back(vctr* v){
    if(v->logVel==0){
        cout<<"Vektor je prazan!"<<endl;
        return NULL;
    }
    return v->el[v->logVel-1];
}

size_t vector_size(const vctr* v){
    if(v->logVel==0){
        cout<<"Vektor je prazan!"<<endl;
        return NULL;
    }
    return v->logVel;
}
