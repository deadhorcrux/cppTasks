#include <bits/stdc++.h>
#define pb push_back

using namespace std;

struct que{
    int item;
    que *next;
};

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

void push(que *&h, que *&t, int x){
    que *r=new que;
    r->item=x;
    r->next=NULL;
    if(!h && !t){
        h=t=r;
    }
    else{
        t->next=r;
        t=r;
    }
}

int pop(que *&h, que *&t){
    que *r=h;
    int x=h->item;
    h=h->next;
    if(!h)
        t=NULL;
    delete r;
    return x;
}

void search_max_min(que *&h, que *&t,int &max,int &min){
    int tmp;
    que *head=NULL;
    que *tail=NULL;
    max=min=pop(h,t);
    push(head,tail,max);
    while(h && t){
        tmp=pop(h,t);
        push(head,tail,tmp);
        if(tmp>max)
            max=tmp;
        if(tmp<min)
            min=tmp;
    }
    h=head;
    t=tail;
}

void ans(que *&h,que *&t,int max,int min){
    que *head=NULL;
    que *tail=NULL;
    int tmp;
    while(h && t){
        tmp=pop(h,t);
        if(tmp==max)
            push(head,tail,min);
        push(head,tail,tmp);
    }
    h=head;
    t=tail;
}

int main() {
    que *h=NULL;
    que *t=NULL;
    int max,min;
    string s;
    vector<int> v;
    getline(cin,s);
    input(s,v);
    for(auto it=v.begin();it!=v.end();it++)
        push(h,t,*it);
    search_max_min(h,t,max,min);
    ans(h,t,max,min);
    while(h && t)
        cout << pop(h,t) << ' ';
    return 0;
}

