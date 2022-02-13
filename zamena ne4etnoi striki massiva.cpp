#include <iostream>
using namespace std;
int main() {
	int size; cout << "size=";
	cin >> size;
	int** nums = new int* [size];
	for (int i = 0; i < size; i++)
		nums[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			cout << "nums[" << i << "][" << j << "]=";
			cin >> nums[i][j];
		}
	for (int i = 0; i < size; i++) {
		bool flag = true;
		for (int j = 0; j < size; j++) 
			if (nums[i][j] %2==0)
				flag = false;
			if (flag)
				for (int j = 0; j < size; j++)
					nums[i][j] = 0;
	}
	for (int i = 0; i < size; i++, cout << endl)
		for (int j = 0; j < size; j++)
			cout << nums[i][j] << ' ';
}