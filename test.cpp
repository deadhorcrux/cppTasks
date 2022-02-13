#include <bits/stdc++.h> 
#define type long double
using namespace std;

type fact(type n ){
    return (n==0) ? 1 : n*fact(n-1);
}

type f(type x, type st) {
    return pow(x,st)/fact(st);
}

int main() { 
    type E=0.001;
    int a=-1;
    int b=1;
    int count=0;
    type x=1;
    int n=20;
    type sum=1;
    for(int i=2; i < n; i+=4){
        sum = sum - f(x,i);
        count+=1;
		cout << "f"<<count<<"(x) = " << -f(x,i) << '\n' << "Sn(x) = " << sum << '\n' << "n = " << count << endl;
		sum = sum  + f(x,i+2);
		count+=1;
		cout << "f" << count <<"(x) = " << f(x,i+2) << '\n' << "Sn(x) = " << sum << '\n' << "n = " << count << endl;
	
        /*if(E - f(x,i) < 2.22045e-016){
            break;
        }*/
    }
   return 0; 
}
