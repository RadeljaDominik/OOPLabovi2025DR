#include <iostream>
#include <vector>

using namespace std;

void input_vector(vector<int>& v){
    int curr=1;
    cout<<"Upiši broj (0 za prekid)"<<endl;
    while(curr!=0){
        cin>>curr;
        cout<<endl;
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

    return 0;
}
