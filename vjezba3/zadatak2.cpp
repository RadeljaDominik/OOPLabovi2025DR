#include <iostream>
#include <cstddef>

using namespace std;

template<typename type>
inline bool ascending (type a, type b){
    return a > b;
}

template<typename type>
inline bool descending (type a, type b){
    return a < b;
}


template<typename type>
void sortt(type niz[], size_t n, bool (*cmp)(int, int)){
    for (size_t i=0;i<n-1;i++){
        for(size_t j=0;j<n-i-1;j++){
            if(cmp(niz[j+1],niz[j])){
                type temp=niz[j];
                niz[j]=niz[j+1];
                niz[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<niz[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int niz[]={1,3,2,4,6,5,8,7};
    size_t n=sizeof(niz)/sizeof(int);
    sortt(niz,n,ascending);
    sortt(niz,n,descending);
    return 0;
}

