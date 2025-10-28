#include <iostream>
#include <string>

using namespace std;

void fix_spaces(string& text){
    if(text.find(" ")!=string::npos){
        size_t pos = text.find(" ");
        if(isspace(text[pos+1])){
            pos++;
            text.erase(pos-1);
        }else{
            pos = text.find(" ",pos);
        }
    }

}

int main(){
    string text = "Puno     razmaka ,i    tocka .";

    return 0;
}
