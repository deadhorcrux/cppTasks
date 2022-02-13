#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float x, y, z;
	setlocale(LC_ALL, "RUS");
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	z = 2 / 5 * (exp(sqrt(x * y) + sqrt(x + y)) + sin(x * y)) / (sqrt(cos(x) * cos(x) + sin(x) * sin(x)));
	cout << z;
	return 0;

}
