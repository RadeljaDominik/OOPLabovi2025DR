#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reverse_strings(vector<string>& words){
    for(auto& r : words){
        reverse(r.begin(),r.end());
    }
}

int main(){
    vector<string> words = {"hello","world","c++"};

    for(const auto& p : words){
        cout<<p<<" ";
    }
    cout<<endl;

    reverse_strings(words);

    for(const auto& n : words){
        cout<<n<<" ";
    }
    cout<<endl;

    return 0;
}
