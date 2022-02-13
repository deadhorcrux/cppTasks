#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class People {
    string salary, fio;
    public:
    string date;
    People(){ salary = fio = ""; }
    People(string str) {
        date = str;
        int k = str.find_first_of(' ');
        fio = str.substr(0, k+1);
        k = str.find_last_of(' ');
        salary = str.substr(k+1, str.length());
    }
    void show();
    int print(vector<People> vec);
    bool operator>(People op2);
};

bool People::operator>(People op2) {
    if((salary < op2.salary) || (salary == op2.salary && fio > op2.fio))
    {
        return true;
    }
    return false;
}

void People::show() {
    cout << fio;
    cout << salary << "\n";
}

void sort_shell(vector<People> &vec) {

    People tmp;
    int n = vec.size();
    int d=n/2;
    while (d > 0)
    {
        for (int j = 0; j < n - d; j++)
        {
            int i=j;
            while(i>=0 && vec[i]>vec[i+d])
            {
               tmp=vec[i];
               vec[i]=vec[i+d];
               vec[i+d]=tmp;
                i--;
            }
        }
        d=d/2;
    }
}



int main() {
    ifstream in("text.txt");
    if(!in) {
    cout << "can't open IN file";
    return -1;
    }
    vector<People> vec;
    string tmp;
    while (in) {
    getline(in, tmp);
    People man(tmp);
    vec.push_back(man);
    }
    in.close();
    sort_shell(vec);
    ofstream out("result.txt");
    if(!out) {
        cout << "can't open OUT file";
        return -1;
    }

    for(int i = 0; i < vec.size(); i++) {
        vec[i].show();
        out << vec[i].date << '\n';
    }
    return 0;
}
