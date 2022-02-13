#include <iostream>
using namespace std;
int main() {
	int rows, couls;
	cout << "rows=";
	cin >> rows;
	cout << "couls=";
	cin >> couls;
	int** nums = new int* [rows];
	for (int i = 0; i < rows; i++)
		nums[i] = new int[couls];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < couls; j++) {
			cin >> nums[i][j];
		}
	int min = nums[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < couls; j++) {
			if (nums[i][j] < min)
				min = nums[i][j];
		}
	bool f;
	for (int i = 0; i < rows; )
	{
		f = false;
		for (int j = 0; j < couls; j++)
			if (nums[i][j] == min) {
				f = true;
				break;
			}
		if (f)
		{
			for (int k = i; k < rows - 1; k++)
				for (int j = 0; j < couls; j++)
					nums[k][j] = nums[k + 1][j];
			rows--; 
		}
		else i++;
	}

	cout << "result:"<<endl;
	for (int i = 0; i < rows; i++, cout << endl)
		for (int j = 0; j < couls; j++) {
			cout << nums[i][j] << ' ';
		}
	return 0;
}