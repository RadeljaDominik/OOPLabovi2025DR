#include <iostream>
#include <cstddef>

using namespace std;

inline bool ascending (int a, int b){
    return (a > b) ? a : b;
}

inline bool descending (int a, int b){
    return (a < b) ? a : b;
}

void sortt(int[], size_t n, bool (*cmp)(int, int)){
    for (int i=0;i<size_t;i++){
        ascending(niz[i],niz[i+1]);
    }
}

int main(){
    int niz[]={1,2,3,4,5,6,7};
    size_t n=sizeof(niz)/sizeof(int);

    return 0;
}
