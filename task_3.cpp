#include <iostream>
#include <cmath>
using namespace std;
int main()

{
	setlocale(LC_ALL, "RUS");

	float x, y, z;
	cout << "x=";
	cin >> x;
	cout << "y=";
	cin >> y;
	z = 2 / 3 * sin(sqrt((x * x - y * y) / (exp(x) + y) + x * x * y * y)) + (cos(x) + sin(y)) / 2;
		cout << z;
		return 0;

	


}