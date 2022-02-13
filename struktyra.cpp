#include <iostream>
#include <string>
using namespace std;
struct Thotel {
	string family;
	string name;
	string soname;
	int godr;
	int dni;
	int d;
};
int main() {
	int n;
	int s1, s2, s3;
	cout << "Koli4estvo tyristov\n";
    cin >> n;
	cout << "1 kategori9 nomera stoit\n";
	cin >> s1;
	cout << "2 kategori9 nomera stoit\n";
	cin >> s2;
	cout << "3 kategori9 nomera stoit\n";
	cin >> s3;
	Thotel* a;
	a = new Thotel[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].family >> a[i].name >> a[i].soname >> a[i].godr >> a[i].dni >> a[i].d;
	}
	double bs1=0;
	double bs2=0;
	double bs3=0;
	for (int i = 0; i < n; i++) {
		if (a[i].d == 1) {
			bs1 += a[i].dni * s1;
		}
		if (a[i].d == 2) {
			bs2 += a[i].dni * s2;
		}
		if (a[i].d == 3) {
			bs3 += a[i].dni * s3;
		}
	}
		for(int i=0;i<n;i++,cout<<endl) {
			if (a[i].d == 1) {
				cout << a[i].family<<" "<< a[i].name<<" "<< a[i].soname<<" "<< "Oplatil=" << bs1<<" ";
			}
			if (a[i].d == 2) {
				cout << a[i].family<<" "<< a[i].name<<" "<< a[i].soname<<" "<< "Oplatil=" << bs2<<" ";
			}
			if (a[i].d == 3) {
				cout << a[i].family<<" "<< a[i].name<<" "<< a[i].soname<<" "<< "Oplatil=" << bs3<<" ";
			}
	}
		return 0;
}