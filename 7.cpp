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

void even(vector<int> &v){
for(vector<int>::iterator it=v.begin(); it!=v.end();)
  {
    if(*it%2==0)
      it = v.erase(it);
    else
      it++;
  }
}

int ans(vector<int> &v,int max, int min,int x){
  int count=0;
  auto it = v.begin();
  for(it=v.begin();it!=v.end();it++){
    if(*it==max){
      v.erase(it);
      v.insert(it, min);
    }
    if(*it%x==0)
      count++;
  }
  return count;
}

void print(vector<int> v){
  for(int i=0; i<v.size(); i++)
    cout << v[i] << ' ';
  cout << '\n';
}

int main(){
  string str; 
  int min, max;
  int x;
  int count;
  vector<int> v;
  cout << "Input sequence\n";
  getline(cin,str);
  str+=" ";
  input(str,v);
  cout << "X = ";
  cin >> x;
  cout << "Vector:\n";
  print(v);
  even(v);
  min = search_min(v);
  max = search_max(v);
  count = ans(v, max, min, x);
  cout << "Result:\n";
  print(v);
  cout << "Count: " << count;
  return 0;
}
