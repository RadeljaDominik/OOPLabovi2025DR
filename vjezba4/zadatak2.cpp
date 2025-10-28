#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void input_vector(vector<int>& v){
    int curr=1;
    cout<<"Upiši broj (0 za prekid)"<<endl;
    while(curr!=0){
        cin>>curr;
        if(curr != 0){
            v.push_back(curr);
        }
    }
}

void print_vector(const vector<int>& v){
    for(const int& out : v){
        cout<<out<<" ";
    }
}

int main(){
    vector<int> v;

    input_vector(v);
    print_vector(v);
    cout<<endl;

    vector<int> vU;
    for(int i : v){
        if(find(vU.begin(),vU.end(),i)==vU.end()){
            vU.push_back(i);
        }
    }

    cout<<"Jedinstveni članovi: ";
    print_vector(vU);
    cout<<endl;

    vector<int> vAbsSort = v;
    sort(vAbsSort.begin(),vAbsSort.end(),[](int a,int b){return abs(a) < abs(b);});

    cout<<"Sortirani po apsolutnoj vrijednosti: ";
    print_vector(vAbsSort);
    cout<<endl;


    return 0;
}
