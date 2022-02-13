#include <iostream>
#include <fstream>

using namespace std;

int main(){
  double ans=1, tmp;
  ifstream input;
  input.open("6cpp.txt");
  while(true){
    input >> tmp;
    if(input.eof())
      break;
    else
      ans*=tmp;
  }
  cout << ans*ans;
  return 0;
}
