#include<iostream>
#include<stdlib.h>
using namespace std;
const int alpha = 26;
typedef struct trie{
    int ncount;
    struct trie *child[alpha];
    bool is_end;
}trie;
trie* init(){
    trie *t = new trie();
    t->ncount = 1;
    for(int i = 0;i<26;i++){
        t->child[i] = NULL;
    }
    t->is_end = false;
    return t;
}
void insert1(trie *root,string str){
    trie *t = root;int ind;
   // cout<<"making for ::  "<<str<<"\n";
    for(int i = 0;i<str.length();i++){
        ind = str[i] - 'a';
        if(!t->child[ind]){
            //(t->ncount)++;
            t->child[ind] = init();
        }
        t = t->child[ind];
    }
    t->is_end = true;
}
void set_node_count(trie *root){
    if(root == NULL){
        return;
    }else{
        trie *t = root;
        for(int i = 0;i<26;i++){
            if(t->child[i]){
                (t->ncount)++;
                //char c = i + 'a';
                //cout<<"char is ::  "<<c<<"  node count is ::  "<<t->ncount<<"\n";
                set_node_count(t->child[i]);
                cout<<"\n";

            }
        }
    }
}
void display(trie *root){
    if(root == NULL){
        return;
    }else{
        trie *t = root;
        for(int i = 0;i<26;i++){
            if(t->child[i]){
                char c = i + 'a';
                cout<<"char is ::  "<<c<<"  node count is ::  "<<t->ncount<<"\n";
                display(t->child[i]);
                cout<<"\n";

            }
        }
    }
}
int main(){
    string str2 ,str = "banana";
    trie *t = init();
    for(int i = 0 ;i <str.length();i++){
        str2.append((const char *)&str[i]);
        insert1(t,str2);
        str2.clear();
    }
    set_node_count(t);
    display(t);
    return 0;
}
