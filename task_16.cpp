#include <iostream>
using namespace std;
int main() {
	int size,x;
	cout << "size=";
	cin >> size;
	cout << "x=";
	cin >> x;
	int* nums = new int[2 * size];
	for (int i = 0; i < size; i++) {
		cout << "nums[" << i << "]=";
		cin >> nums[i];
	}
	int max = nums[0];
	for (int i = 0; i < size; i++) {
		if (max < nums[i]) {
			max = nums[i];
		} 
	}
	for (int i = 0; i < size; i++)
		if (nums[i] == max)
		{
			for (int j = size; j > i; j--)
				nums[j] = nums[j - 1];
			    size++; 
			    nums[i] = x; 
			    i++; 
		}
	for (int i = 0; i < size; i++)
		cout << nums[i] << " ";
	return 0;
}