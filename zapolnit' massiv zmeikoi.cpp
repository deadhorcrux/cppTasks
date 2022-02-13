#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int size; cout << "size=";
    cin >> size;
    int** nums = new int* [size];
    int t=0;
    for (int i = 0; i < size; i++)
        nums[i] = new int[size];
    for(int i = size - 1;i>=0;i--)
        if (i % 2 == 0) {
            for (int j = 0; j < size; j++) {
                nums[i][j] = t;
                t++;
            }
        }
        else {
            for (int j = size - 1; j >= 0; j--){
                nums[i][j] = t;
                t++;
            }
        }
    for(int j=0;j<size;j++,cout<<endl)
        for (int i = 0; i < size; i++) {
            cout << nums[i][j] << ' ';            
        }
    return 0;
}