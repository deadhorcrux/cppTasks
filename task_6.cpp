#include <iostream>
using namespace std;
int main() {
	int size;
	cout << "size=";
	cin >> size;
	int x;
	cout << "x=";
	cin >> x;
	int* nums = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "nums[" << i << "]=";
		cin >> nums[i];
	}
	for (int i = 0; i < size;i++) {
		if (nums[i] % 10 == x)
		{
			for (int j = i; j < size - 1; j++)
				nums[j] = nums[j + 1];
			size--;
		}

		else i++;
	}
	for (int i = 0; i < size; i++)
		cout << nums[i] << " ";
	return 0;
}