#include <bits/stdc++.h>

using namespace std;

void println (set<string> s){
  for(set<string>::iterator it = s.begin();
      it != s.end(); it++){
    cout << *it << " ";
  }
  cout << "\n";
}

string str_tolower(string& s){
  for (int i=0; i<s.length(); i++)
    s[i] = tolower(s[i]);
  return s;
}

set<string> set_word(string s) {
  set<string> set_s;
  if(s[s.length()-1] != ' ')
    s+=" ";
  while (s!=""){
    set_s.insert(s.substr(0,s.find(' ')));
    s.erase(0,s.find(' ')+1);
  }
  return set_s;
}

int main() {
  string s, pr;
  ifstream in;
  in.open("9cpp.txt");
  getline(in, s);
  str_tolower(s);
  set<string> res, pov, voskl, vopr, s0;
  while(s!=""){
    int pos = s.find_first_of(".!?");
    pr=s.substr(0,pos);
    s0 = set_word(pr);
    if (s[pos] == '.') pov.insert(s0.begin(), s0.end());
    if (s[pos] == '!')voskl.insert(s0.begin(), s0.end());
    if (s[pos] == '?') vopr.insert(s0.begin(), s0.end());
    s.erase(0, pos + 1);
  }
 set_intersection(pov.begin(), pov.end(), voskl.begin(), voskl.end(), inserter(res, res.begin()));
 println(res);
 return 0;
}
