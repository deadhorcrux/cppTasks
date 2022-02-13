#include <iostream>

using namespace std;

int func(int n, int m){
  if(n == 1)
    return m;
  return (m-n+1)*func(n-1, m);
}

int main() { 
  int n, m;
  cout << "n = ";
  cin >> n;
  cout << "m = ";
  cin >> m;
  if (m < n){
    cout << "Incorrect input n should be more then m\n";
    return 1;
  }
  cout << func(n,m);
  return 0;
}
