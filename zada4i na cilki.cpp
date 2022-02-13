#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	double a, b, h;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "h=";
	cin >> h;
	if (a > b) swap(a, b);
	for (double x=a; x<b+h; x+=h)
	{
		if (x < 1) cout << "Логорифм неположительного числа\n";
		else if (x < 3) cout << "Корень из отрицательного числа\n";
		else if (x == 4) cout << "Деление на ноль\n";
		else {double y = log(x * x - 2 * x + 1) / (1 - sqrt(x - 3));
		cout << "x=" << x << " ";
		cout << "y=" << y << endl;
		}
	}
	return 0;
}