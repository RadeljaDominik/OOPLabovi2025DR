#include <iostream>
#include <string>

using namespace std;

char& at(string& str, int i) {
	return str[i];
}

int main() {
	string s("123a45bcd6");
	cout << s << endl;
	int i;
	cin >> i;
	at(s, i) += 1;
	cout << s << endl;
}

/*
ONRIBL MENŠN

#include <iostream>
#include <string>

using namespace std;

int& at(int s[], int i) {
	return s[i];
}

int main() {
	int s[]={1,2,3,4,5,6,7,8,9};
	for(int z=0;z<9;z++){
		cout<<s[z]<<" ";
	}
	cout<<endl;
	int i;
	cin >> i;
	at(s, i) += 1;
	for(int z=0;z<9;z++){
		cout<<s[z]<<" ";
	}
}

*/