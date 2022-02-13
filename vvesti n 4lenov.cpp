#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cout << "n=";
	cin >> n;
	float y;
	float y1 = 0.5;
	float y2 = 0.4;
	cout << "y1=" << y1 << endl << "y2=" << y2 << endl;
	for (int i = 3; i <= n; i++) {
		y = y1/(i - 1) + y2/(i - 2);
		cout << "y" << i << "=" << y << endl;
		y1 = y2;
		y2 = y;
	}
	return 0;
}


