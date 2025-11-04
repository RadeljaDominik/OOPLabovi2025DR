#include <iostream>
#include <string>

using namespace std;

void fix_spaces(string& text){
    size_t pos;
    while ((pos = text.find("  ")) != std::string::npos) {
        text.erase(pos, 1);
    }
    while ((pos = text.find(" ,")) != std::string::npos) {
        text.erase(pos, 1);
    }
    while ((pos = text.find(" .")) != std::string::npos) {
        text.erase(pos, 1);
    }
    pos = 0;
    while ((pos = text.find(",", pos)) != std::string::npos) {
        if (pos + 1 < text.size() && text[pos + 1] != ' ') {
            text.insert(pos + 1, " ");
        }
        pos++;
    }
}

int main(){
    string text = "Puno     razmaka ,i    tocka .";
    fix_spaces(text);
    cout<<text;

    return 0;
}
