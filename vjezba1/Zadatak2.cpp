#include <iostream>

using namespace std;

int funk(int x, int low = 3, int high = 12) {
	if (x > high) {
		return high;
	}
	else if (x < low) {
		return low;
	}
	else {
		return x;
	}
}

double funk(double dx, double low = 7.25, double high = 13.72) {
	if (dx > high) {
		return high;
	}
	else if(dx < low){
		return low;
	}
	else {
		return dx;
	}
}

int main() {
	cout<<funk(7)<<endl;
	cout<<funk(13.73)<<endl;
	cout<<funk(4)<<endl;
}