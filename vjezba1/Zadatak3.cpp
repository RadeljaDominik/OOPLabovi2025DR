#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (auto& n : s) {
		n=toupper(n);
		if (isdigit(n)) {
			n = '*';
		}
		if (isspace(n)) {
			n = '_';
		}
	}
	cout << s << endl;
}