#include <bits/stdc++.h>
#define pb push_back

using namespace std;

void input(string &s, vector<int> &v){
  s+=" ";
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

void make_set(vector<int> v, set<int> &s1, set<int> &s2){
  auto it = v.begin();
  for(it = v.begin();it!=v.end();it++){
    if(*it/100 > 0 && *it/100 <= 9){
      //write in set 3-x
      int t = *it/100;
      int s = (*it/10)%10;
      int f = *it%10;
      s2.insert(t);
      s2.insert(s);
      s2.insert(f);
    }
    if(*it/100 == 0){
      //write in set 2-x
      int s = *it/10;
      int f = *it%10;
      s1.insert(s);
      s1.insert(f);
    }
  }
}
    
void print (set<int> s){
  for(set<int>::iterator it=s.begin();
      it!=s.end(); it++){
    cout << *it << " ";
  }
  cout << "\n";
}
  

int main(){
  vector<int> v;
  string s;
  set<int> s1;
  set<int> s2;
  set<int> res;
  getline(cin,s);
  input(s,v);
  make_set(v, s1, s2);
  set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
  if(res.empty())
    cout << "No such element's\n";
  print(res);
  return 0;
}
