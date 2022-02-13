#include <bits/stdc++.h>
#define pb push_back

using namespace std; 

struct lis{
    int item;
    lis *next;
    lis *prev;
};

void print_list(lis *h, lis *t){
    lis *p=h;
    while(p){
        cout<<p->item<<' ';
        p=p->next;
    }
}


void push(lis *&h, lis *&t, int x){
    lis *p= new lis;
    p->item=x;
    p->next=NULL;
    if(!h && !t){
        p->prev=NULL;
        h=p;
    }
    else{
        t->next=p;
        p->prev=t;
    }
    t=p;
}

void del_node(lis *&h, lis *&t, lis *r){
    if(r==h && r==t){
        h=NULL;
        t=NULL;
    }
    else if(r==h){
        h=h->next;
        h->prev=NULL;
    }
    else if(r==t){
        t = t->prev;
        t->next=NULL;
    }
    else{
        r->next->prev=r->prev;
        r->prev->next=r->next;
    }
    delete r;
}

void ans(lis *&h, lis *&t){
    lis *p=h;
    lis *ans=h;
    int lastEl;
    while(p){
        lastEl=p->item;
        p=p->next;
    }
    while(ans){
        lis *tmp=ans->next;
        if(lastEl==ans->item)
            del_node(h,t,ans);
        ans=tmp;
    }
}

void input(string s, vector<int> &v){
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

int main(){
    string s;
    lis *h=NULL;
    lis *t=NULL;
    vector<int> v;
    getline(cin, s);
    s+=" ";
    input(s, v);
    for(int i=0;i<v.size();i++){//check inpiut somthing wrongh
        push(h,t,v[i]);
    }
    ans(h,t);
    print_list(h,t);
    return 0;
}
