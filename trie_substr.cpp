#include<iostream>
#include<stdlib.h>
using namespace std;
const int alpha = 26;
typedef struct trie{
    struct trie *child[alpha];
    bool is_end;
}trie;
trie* getNode(){
    trie *t = new trie();
    for(int i =0;i<26;i++){
        t->child[i] = NULL;
    }
    t->is_end = false;
    return t;
}
void construct(trie *root, string str){
    trie *t = root;int ind ;
    cout<<"constructing for          "<<str<<"\n";
    for(int i = 0;i<str.length();i++){
        ind = str[i]-'a';
        if(!t->child[ind]){
            t->child[ind] = getNode();
        }
        t  = t->child[ind];
    }
    t->is_end = true;
}
void count1(trie *root, int *c){

    trie *t = root;

    for(int i = 0;i<26;i++){

        if(t->child[i]){
            (*c)++;
            //cout<<"\n@@@@@\n";
            count1(t->child[i],c);
        }
    }
}
int main(){
    string str,str2;
    cin>>str;
    trie *root = getNode();
    for(int i = 0; i<str.length();i++){
        str2.append((const char *)&str[i]);
        construct(root,str2);
        str2.clear();
    }
    int c = 0;
    count1(root,&c);
    cout<<"\n"<<c+1;
    return 0;
}
