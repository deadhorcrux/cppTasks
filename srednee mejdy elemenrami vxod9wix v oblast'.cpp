#include <iostream>
using namespace std;
int main() {
	int size; cout << "size=";
	cin >> size;
	float sum=0;
	float n = 0;
	float avg;
	int** nums = new int* [size];
	for (int i = 0; i < size; i++)
		nums[i] = new int[size];
	for(int i=0;i<size;i++)
		for (int j = 0; j < size; j++) {
			cout << "nums[" << i << "][" << j << "]=";
			cin >> nums[i][j];
		}
	int k = 0;
	bool flag = true;
	for(int i=0;i<size;i++)
		for (int j = 0; j < size; j++) {
			if ((j <= i && j <=size-1-i) || (j >= i && j >=size-1-i)) {
				if(nums[i][j]%2)
				sum += nums[i][j];
				k++;
				flag = false;

			}
		}
	if (!flag) {
		avg = sum / k;
		cout << avg;
	}
	if (flag) {
		cout << "net takix elementov";
	}
	return 0;
	                                           
}