#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void sort_shell(vector<int> &v) {
    int n = v.size();
     vector<int> tmp(n);
    for(int i=0; i<n;i++){
        tmp[i] = 0;
    }
    int d=n/2;
    while (d > 0)
    {
        for (int j = 0; j < n - d; j++)
        {
            int i=j;
            while(i>=0 && v[i]>v[i+d])
            {
               tmp[i]=v[i];
               v[i]=v[i+d];
               v[i+d]=tmp[i];
                i--;
            }
        }
        d=d/2;
    }
}
void Sort_shell(vector<int> &v) {
    int n = v.size();
     vector<int> tmp(n);
    for(int i=0; i<n;i++){
        tmp[i] = 0;
    }
    int d=n/2;
    while (d > 0)
    {
        for (int j = 0; j < n - d; j++)
        {
            int i=j;
            while(i>=0 && v[i]<v[i+d])
            {
               tmp[i]=v[i];
               v[i]=v[i+d];
               v[i+d]=tmp[i];
                i--;
            }
        }
        d=d/2;
    }
}


int main() {
    ifstream in("text.txt");
    if(!in){
        cout << "can't open file";
        return -1;
    }
    int tmp;
    int n;
    in >> n;
    vector<vector<int> > nums(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            in>>tmp;
            nums[i].push_back(tmp);
        }
    vector<int> x;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            x.push_back(nums[i][j]);
        }
    if(j%2==0) {sort_shell(x);}
    else { Sort_shell(x);}
    for(int i = 0; i < n; i++){
        nums[i][j]=x[i];
    }
    x.clear();
    }
    in.close();
    ofstream out("res.txt");
    cout << "sort massiv:\n";
    for(int i = 0; i < nums.size(); i++,cout<<endl){
        for(int j =0; j < nums[i].size(); j++){
            cout << nums[i][j] << ' ';
            out << nums[i][j] << ' ';
        }
        out << endl;
    }
    return 0;
}


