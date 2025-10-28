#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> niz = {1,2,3,4,5,6};
    int sum,prod;
    int s;
    int prag=3;


    auto parni = [](int n)->bool{return n%2==0;};
    auto neparni = [](int n)->bool{return n%2==1;};
    auto doub = [](int n)->int{return n*2;};
    auto halv = [](int n)->int{return n/2;};

    auto addSum = [&](int n){return sum+=n;};
    auto addProd = [&](int n){return prod*=n;};

    auto addPrag = [prag,&s](int n){
        if(n>prag){
            return s+=n;
        }
    };

    auto parPrepNepDoub = [&](){
        for(int& broj : niz){
            if(parni(broj)){
                broj=halv(broj);
            }else if(neparni(broj)){
                broj=doub(broj);
            }
        }
        return niz;
    };

    auto sumProd = [&](int& sum){
        int prod=0;

        for(int broj : niz){
            sum+=broj;
            prod*=broj;
        }
        return prod;
    };

    auto zbrojiVece = [&](int prag)->int{
        int rezz=0;

        for(int broj : niz){
            rezz+=addPrag(broj);
        }
        return rezz;
    };


    return 0;
}
