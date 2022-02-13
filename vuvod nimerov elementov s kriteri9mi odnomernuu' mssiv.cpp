#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int x; cout << "x=";
	cin >> x;
	const int n = 8;
	int mass[n];
	for (int i = 0; i < 8; i++) {//vvod elementov maccuva
		cout << "mass[" << i << "]=";
		cin >> mass[i];
	}
	bool flag = true;
	for (int i = 0; i < 8; i++) {//vuvod nomerov elementov pru yslovuu ne kratnostu x
		if (mass[i] % x) {
			cout << i << ' ';
			flag = false;
		}
	}
	if (flag)
		cout << "takix elementov net";
	return 0;
	
}