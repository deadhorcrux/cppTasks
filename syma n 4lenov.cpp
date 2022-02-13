#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int n;
	float sum, x, a;
	sum = 0;//сумма изначльно равна нулю
	cout << "x="; cin >> x;
	cout << "n="; cin >> n;
	a = x * x / 2;//начальные значения а получено подставлением нуля в исходную формулу это А0
	for (int i = 1; i <= n; i++) {//можно использовать цикл фор потому что сумма конечная если сумма бесконечна то нужен цикл ваил
		a *= -(x * x) / (2 * i + 3) * (2 * i + 4);//выводим рекурентную формулу путем:An+1/An
		sum += a;
	}
	cout << "sum=" << sum << endl;
	return 0;
}
