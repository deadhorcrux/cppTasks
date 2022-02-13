#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void buble_sort(vector<int> &v){
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size() - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
   }
}

int main () {
    int i, j;
    int p, k;
    int n;
    int tmp;
    ifstream in("text.txt");
    if (!in){
        cout << "can't opne file";
        return -1;
    }
    in >> n;
    vector<vector<int> > mas(n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            in >> tmp;
            mas[i].push_back(tmp);
        }
    }
    vector<int> diagonals;
    for ( k = 1; k < n; k++)
    {
        for(j = 0, i = k; i >=0; j++, i--) {
            diagonals.push_back(mas[i][j]);
        }
        buble_sort(diagonals);
        for (j = 0, i = k; i >= 0; j++, i--){
            mas[i][j] = diagonals[j];
        }
        diagonals.clear();
    }
    for( k = 1; k < n; k++) {
        for(j = k, i = n-1; j < n; j++, i--){
            diagonals.push_back(mas[i][j]);
        }
        buble_sort(diagonals);
        for(j = k, i =n -1, p = 0; j < n; j++, i--, p++) {
            mas[i][j] = diagonals[p];
        }
        diagonals.clear();
    }
    in.close();
    for(i = 0; i < mas.size(); i++,cout << endl)
        for(j = 0; j < mas[i].size(); j++)
            cout << mas[i][j] << ' ';
    return 0;
}
