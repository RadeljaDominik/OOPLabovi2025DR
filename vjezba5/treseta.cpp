#include <iostream>

using namespace std;

class karta {
    public:
        int broj;
        char zog;
};

class mac {
    public:
        karta[40] mKarti;

};

class igrac {
    public:
        string ime;
        int bodovi;
        karta[10] ruka;
};

int main(){
    int brojigraca;
    cout<<"Unesi broj igraca (2 ili 4)"<<endl;
    cin>>brojigraca;
    switch(brojigraca){
    case 2:

        break;
    case 4:

        break;
    default:
        cout<<"Nemoguc broj igraca!";
        break;
    }

    return 0;
}
