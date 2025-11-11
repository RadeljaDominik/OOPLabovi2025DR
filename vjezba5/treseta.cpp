#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

class karta {
    public:
        int broj;
        char zog;

        karta(char z, int b){
            broj = b;
            zog = z;
        }
        void ispis(){
            cout<<broj<<" "<<zog;
        }
};

class mac {
    vector <karta> mkarti;
    public:
        mac(){
            vector <char> mzog = {'K','S','B','D'};
            for(const auto &z : mzog){
                for(int i=1;i<11;i++){
                    mkarti.push_back(karta(z,i));
                }
            }
        }
        void mijesanje(){
            auto rng = default_random_engine{};
            shuffle(mkarti.begin(),mkarti.end(),rng);
        }
        vector<karta> dijeli(int n){
            vector<karta> ruka;
            for(int i=0; i<n && !mkarti.empty(); i++){
                ruka.push_back(mkarti.back());
                mkarti.pop_back();
            }
            return ruka;
        }
};

class igrac {
    string ime;
    int bodovi=0;
    vector <karta> ruka;
    public:
        igrac(string i){
            ime = i;
        }
        void nRuka(vector<karta> k){
            ruka = k;
        }
        void outRuka(){
            cout<<endl<<ime<<endl<<"Ruka: ";
            for(auto &k : ruka){
                cout<<" ";
                k.ispis();
                cout<<" ";
            }
        }
        void akuza(){
            vector<char> zog = {'K','S','B','D'};
            for(auto &z : zog){
                bool A1=false;
                bool A2=false;
                bool A3=false;
                for(auto &k : ruka){
                    if(k.zog == z){
                        if(k.broj == 1){
                            A1 = true;
                        }
                        else if(k.broj == 2){
                            A2 = true;
                        }
                        else if(k.broj == 3){
                            A3 = true;
                        }
                    }
                }
                if(A1 && A2 && A3){
                    bodovi +=3;
                }
            }

            for(int i=1; i<11; i++){
                int brojac=0;
                for(auto &k : ruka){
                    if(k.broj==i){
                        brojac++;
                    }
                }
                if(brojac == 3){
                    bodovi+=3;
                }
                else if(brojac == 4){
                    bodovi +=4;
                }
            }
        }
        int outBodovi(){
            return bodovi;
        }

        string outIme(){
            return ime;
        }
};

int main(){
    int brojigraca;
    cout<<"Unesi broj igraca (2 ili 4)"<<endl;
    cin>>brojigraca;
    if(brojigraca!=2 && brojigraca != 4){
        cout<<"Nemoguc broj igraca!";
        return 1;
    }

    vector<igrac> igraci;
    for(int i=0; i<brojigraca; i++){
        string ime;
        cout<<"Unesi ime igraca"<<endl;
        cin>>ime;
        cout<<endl;
        igraci.push_back(ime);
    }

    mac nmac;
    nmac.mijesanje();

    for(auto &igrac : igraci){
        igrac.nRuka(nmac.dijeli(10));
        igrac.akuza();
    }

    cout<<"Rezultati: "<<endl;
    for(auto &igrac : igraci){
        igrac.outIme();
        cout<<endl;
        igrac.outRuka();
        cout<<endl;
        cout<<"Bodovi: "<<igrac.outBodovi()<<endl;
    }
    return 0;
}
