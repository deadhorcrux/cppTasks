#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, max,imax;
	cout << "n=";
	cin >> n;
	int* mass = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "mass[" << i << "]=";
		cin >> mass[i];}
	max = -1;
	for (int i = 0; i < n; i++) {//opredel9em 4etnuu' maximum
		if (mass[i] > max && mass[i]%2==0) {
			max = mass[i];
		}
	}
	if (max == -1) cout << "net 4etnux";
	else 
		for (int i = 0; i < n; i++) {
			if (mass[i] == max)
				cout << i << ' ';

		}
	return 0;
}