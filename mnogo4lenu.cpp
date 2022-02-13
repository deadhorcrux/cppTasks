#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int size;
	char x;
	cout << "size="; cin >> size;
	int* nums = new int[size + 1];
	for (int i = size; i >= 0; i--) //zapolnenie s konca 4tobi sovpadala stepen' i index
		cin >> nums[i];
	float* integral = new float[size + 2];//+2 potomy4to vsegda po9vl9ets9 svobodnuu' 4len
	integral[0] = 0;
	for (int i = 1; i < size + 2; i++)
		integral[i]=nums[i - 1] * 1.0 / i;
	for (int i = 0; i < size + 2; i++)
		cout << integral[i] << " ";
}