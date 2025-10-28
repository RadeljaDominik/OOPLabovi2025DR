#include <iostream>
#include <string>

using namespace std;

string word_to_pig_latin(const string& word){
    string rez;
    if(tolower(word.front())=='a' || tolower(word.front())=='e' || tolower(word.front())=='i' || tolower(word.front())=='o' || tolower(word.front())=='u' ){
        rez=rez+word+"hay";
    }else{
        char pr = tolower(word.front());
        string sub=sub+word.substr(1,word.length()-1);
        rez=rez+sub+pr+"ay";
    }
    return rez;
}

int main(){
    string word1 = "apple";
    string word2 = "hello";

    string rez1 = word_to_pig_latin(word1);
    string rez2 = word_to_pig_latin(word2);

    cout<< rez1 <<endl;
    cout<< rez2 <<endl;

    return 0;
}
