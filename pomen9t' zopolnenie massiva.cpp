#include <iostream>
#include <cmath>
using namespace std;
void main() {
	int n; cin >> n;//massiv razmerom nxn 
	int** massA = new int* [n];
	for (int i = 0; i < n; i++) {
		massA[i] = new int[n];
	}
	for (int i = 0; i < n; i++)//vvod danux massiva rykami
		for (int j = 0; j < n; j++) {
			cout << "massA[" << i << "]" << "[" << j << "]=";
			cin >> massA[i][j];
		}
	for (int i = 0; i < n / 2; i++)
		swap(massA[i], massA[n - i - 1]);//zamena stro4ek esli i=0 to men9et s n-0-1 t.e. s posledneu' i td


	for(int i=0;i<n;i++,cout<<endl)//vuvod iskomogo massiva
		for (int j = 0; j < n; j++) {
			cout << massA[i][j] << ' ';
		}

}