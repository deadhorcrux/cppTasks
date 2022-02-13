#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class People {
    string fio;
    string work_experience, salary;
        public:
    string all;
    People() {
    fio = "";
    work_experience = salary = "";
}

People(string str) {
    all = str;
    int k = str.find_first_of(' ');
    fio = str.substr(0, k+1);
    str.erase(0, k+1);
    k = str.find_first_of(' ');
    //post = str.substr(0, k+1);
    str.erase(0, k+1);
    k = str.find_first_of(' ');
    str.erase(0, k+1);
    k = str.find_first_of(' ');
    work_experience = str.substr(0, k+1);
    str.erase(0, k+1);
    salary = str;
}

bool operator>(People op2);
void show();
};


bool People::operator>(People op2) {
    if((fio > op2.fio) 
            || (fio == op2.fio && work_experience < op2.work_experience) 
            || (fio == op2.fio && work_experience == op2.work_experience && salary < op2.salary))
    {
        return true;
    }
    return false;
}

void People::show() { cout << all << '\n'; }

void oddEvenSorting(vector<People> &vec) {
	for (int i = 0; i < vec.size(); i++) {
	    // (i % 2) ? 0 : 1 возвращает 1, если i четное, 0, если i не четное
		for (int j = (i % 2) ? 0 : 1; j + 1 < vec.size(); j += 2) {
			if (vec[j] > vec[j + 1]) {
				swap(vec[j], vec[j + 1]);
			}
		}
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
    oddEvenSorting(vec);
    ofstream out("result1.txt");
    if(!out) {
        cout << "can't open OUT file";
        return -1;
    }
    for(int i = 0; i < vec.size(); i++) {
        vec[i].show();
        out << vec[i].all << '\n';
    }
    return 0;
}
