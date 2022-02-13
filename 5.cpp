#include <bits/stdc++.h>
#define pb push_back

using namespace std;

void input(string s, vector<int> &v){
  while(true){
  int pos = s.find(" ");
  string tmp = s.substr(0, pos);
  int n = stoi(tmp);
  v.pb(n);
  s.erase(0, pos+1);
  if(s.length() == 0)
    break;
  }
}

int search_max(vector<int> v){
  int max = v[0];
  for(int i = 0 ; i < v.size(); i++){
    if(max < v[i])
      max = v[i];
  }
  return max;
}

int search_min(vector<int> v){
  int min = v[0];
  for(int i=0; i<v.size(); i++){
    if(min > v[i])
      min = v[i];
  }
  return min;
}

void ans(vector<int> &v, int min, int max){
  for(int i=0; i<v.size(); i++){
    if(v[i]==min){
      auto it = v.begin()+i+1;
      v.insert(it,max);
    }
  }
}

void print(vector<int> v){
  for(int i=0; i<v.size(); i++)
    cout << v[i] << ' ';
  cout << '\n';
}

int main(){
  int min, max;
  int n;
  string str;
  vector<int> v;
  getline(cin, str);
  str+=" ";
  input(str,v);
  cout << "Input:\n";
  print(v);
  min = search_min(v);
  max = search_max(v);
  ans(v, min, max);
  cout << "Output:\n";
  print(v);
  return 0;
}
