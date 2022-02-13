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

tree *search_tree(tree *l, int x){
    if(l == NULL) return NULL;
    if(l->item == x) return l;
    if(x<l->item)
        return search_tree(l->left,x);
    else
        return search_tree(l->right,x);
}

int ans(tree *l){
    if(l!=NULL){
        int left=ans(l->left);
        cout<<l->item<<' ';
        return left+1;
    }
}

int main(){
    int x;
    tree *parent=NULL;
    string s;
    vector<int> v;
    getline(cin,s);
    input(s,v);
    for(int i=0;i<v.size();i++)
        insert_tree(&parent,v[i],parent);
    cout << "enter node to be found\n";
    cin >> x;
    ans(search_tree(parent, x));
    return 0;
}
