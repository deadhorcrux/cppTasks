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

void print(vector<int> v){
  auto it = v.begin();
  for(it=v.begin();it!=v.end();it++)
    cout << *it << ' ';
  cout << '\n';
}

int search_max(vector<int> v){
  int max = v[0];
  for(int i = 0 ; i < v.size(); i++){
    if(max < v[i])
      max = v[i];
  }
  return max;
}

void eraseDuplicateElement(vector<int> &v1, vector<int> &v2){
  for(int i=0; i<v1.size();i++)
    for(int j=0; j<v2.size();j++){
      if(v1[i]==v2[j]){
        auto it = v1.begin()+i;
        v1.erase(it);
      }
    }
}

void insertNewElement(vector<int> &v, int x){
  for(vector<int>::iterator it=v.begin();
      it!=v.end();it++){
    if(*it%x==0){
      v.insert(it+1,search_max(v)+1);
    }
  }
}

int main(){
  string str_f, str_s;
  vector<int> v1;
  vector<int> v2;
  int x;
  cout << "Input 2 sequence:\n";
  getline(cin, str_f);
  getline(cin,str_s);
  str_f+=" ";
  str_s+=" ";
  input(str_f,v1);
  input(str_s,v2);
  cout << "Input X = ";
  cin >> x;
  eraseDuplicateElement(v1, v2);
  insertNewElement(v2,x);
  /*sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  v1.insert(v1.end(),v2.begin(),v2.end());*/
  return 0;
}
