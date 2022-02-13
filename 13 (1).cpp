#include <fstream>

using namespace std;

int main(){
  int tmp;
  double ans;
  ifstream input;
  input.open("13cppInput.txt");
  ofstream output;
  output.open("13cppOutput.txt");
  while(true){
    input >> tmp;
    if(input.eof())
      break;
    else {
      if(tmp%3==0 && tmp%7!=0)
        output << tmp << ' ';
    }
  }
  return 0;
}
