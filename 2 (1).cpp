#include <iostream>
#include <fstream>

using namespace std; 

int main(){
  double d=0;
  double tmp;
  ifstream output;
  output.open("2cpp.txt");
  while(true){
    output >> tmp;
    if (output.eof())
      break;
    else
      d+=tmp;
  }
  cout << d;
  return 0;
}
