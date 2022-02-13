#include <iostream>
#include <string>
using namespace std;
struct Student {
	string familly;
	string name;
	string soname;
	string born;
	int predmet1;
	int predmet2;
	int predmet3;
	int predmet4;
};
int main(){
	int n;
	cout << "kol-vo studentov \n";
	cin >> n;
	Student* gr;
	gr = new Student[n];
	for (int i = 0; i < n; i++) {
		cin >> gr[i].familly >>
			gr[i].name >>
			gr[i].soname >>
			gr[i].born >>
			gr[i].predmet1 >>
			gr[i].predmet2 >>
			gr[i].predmet3 >>
			gr[i].predmet4;
	}
	for (int i = 0; i < n; i++) {
		if (gr[i].predmet1 >= 3 && gr[i].predmet2
			&& gr[i].predmet3 >= 3 && gr[i].predmet4 >= 3) {
			cout << gr[i].familly << ' ' <<
				gr[i].name << ' ' <<
				gr[i].soname << ' ' <<
				gr[i].born << endl;

		}
	}
	return 0;
	system("pause");
}