#include <bits/stdc++.h>
#define pb push_back

using namespace std;

struct tree{
    int item;
    tree *parent;
    tree *left;
    tree *right;
};

void input(string &s, vector<int> &v){
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

int insert_tree(tree **l, int x, tree *parent){
    if(*l==NULL){
        tree *p=new tree;
        p->item=x;
        p->right=NULL;
        p->left=NULL;
        p->parent=parent;
        *l=p;
        return 0;
    }
    if(x<(*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);
}

tree *ans(tree *l,int &count){
    if(l == NULL) return NULL;
    if(l->left==NULL && l->right!=NULL) count++;
    ans(l->left,count);
    ans(l->right,count);
}

int main(){
    int x=0;
    tree *parent=NULL;
    string s;
    vector<int> v;
    getline(cin,s);
    input(s,v);
    for(int i=0;i<v.size();i++)
        insert_tree(&parent,v[i],parent);
    ans(parent,x);
    cout << x;
    return 0;
}
