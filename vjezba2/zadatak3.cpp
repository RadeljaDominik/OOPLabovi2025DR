#include <iostream>

using namespace std;

double** numat(int m, int n) {
	double** mat = new double*[m];
	for (int i = 0; i < m; i++) {
		mat[i] = new double[n];
	}
	return mat;
}

void inmat(double** mat, int m, int n) {
	for (int r = 0; r < m; r++) {
		for (int s = 0; s < n; s++) {
			cout << "Element matrice " << r << "," << s << "= ";
			cin >> mat[r][s];
		}
	}
}

double** zbrojm(double** mat1, double** mat2, int m, int n) {
	double** rezz = numat(m, n);
	for (int r = 0; r < m; r++) {
		for (int s = 0; s < n; s++) {
			rezz[r][s] = mat1[r][s] + mat2[r][s];
		}
	}

	return rezz;
}

double** oduzm(double** mat1, double** mat2, int m, int n) {
	double** rezo = numat(m, n);
	for (int r = 0; r < m; r++) {
		for (int s = 0; s < n; s++) {
			rezo[r][s] = mat1[r][s] - mat2[r][s];
		}
	}

	return rezo;
}

double** umnm(double** mat1, double** mat2, int m, int n) {

}

int main() {
	int m, n;
	cout << "Unesi dimenzije matrice" << endl;
	cin >> m;
	cin >> n;

	double** mat = numat(m, n);


}