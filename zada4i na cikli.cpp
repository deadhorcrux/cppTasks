#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, k;
	cout << "n=";
	cin >> n;
	cout << "k=";
	cin >> k;
	int res = (1.0 / n) * 10;
	cout << res;
	for (int i = 2; i <= k; i++)
	{
		res = (1.0 / n) * pow(10, i);
		res = res % 10;
		cout << res;
	}
	return 0;
}