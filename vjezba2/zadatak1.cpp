#include <iostream>

using namespace std;

int* fibon(int n) {
	int* sek = new int[n];
	sek[0] = 1;
	sek[1] = 1;
	for (int i = 2; i < n; i++) {
		sek[i] = sek[i - 1] + sek[i - 2];
	}
	return sek;
}

int main() {
	int n;
	cout << "Upisi duljinu sekvence" << endl;
	cin >> n;

	int* sek = fibon(n);
	for (int i = 0; i < n; i++) {
		cout << sek[i] << " ";
	}

	delete[] sek;
	sek = nullptr;

	return 0;
}