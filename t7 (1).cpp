#include <bits/stdc++.h>
#define pb push_back

using namespace std; 

struct st {
    int item;
    st *next;
};

int pop(st *&h){
    int item = h->item;
    st *r = h;
    h = h->next;
    delete r;
    return item;
}

int check(st *&h){
    int tmp = h->item;
    h = h->next;
    return tmp;
}

void input(string s, vector<int> &v){
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

void push(st *&h, int item) {
    st *r = new st;
    r->item = item;
    r->next = h;
    h=r; 
}

void reverse(st *&h){
    st *head = NULL;
    while(h)
        push(head,check(h));
    h = head;
}

int sum_nums(int x){
    int sum=0;
    while(x!=0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int search_max(st *h){
    st *tmp=NULL;
    int max=0;
    int n, s;
    while(h){
        n = pop(h);
        push(tmp, n);
        s = sum_nums(n);
        if(s>max){
            max=s;
        }
    }
    reverse(tmp);
    h=tmp;
    return max;
}

void ans(st *h, int x){
    int n;
    st *ans=NULL;
    while(h){
        n=pop(h);
        if(x != sum_nums(n))
            push(ans,n);
    }
    while(ans){
        cout << pop(ans) << ' ';
    }
}


int main() {
    string s;
    int max;
    vector<int> v;
    st *h = NULL;
    getline(cin, s);
    input(s, v);
    for(int i=0;i<v.size();i++){
        push(h, v[i]);
    }
    max=search_max(h);
    ans(h,max);
    return 0;
}
