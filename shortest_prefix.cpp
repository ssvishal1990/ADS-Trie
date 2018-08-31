#include<iostream>
#include<stdlib.h>
using namespace std;
const int alpha = 26;
typedef struct trie{
    struct trie* child[alpha];
    int freq;
    bool is_end;
}trie;
trie* getNode(){
    trie *t = new trie();
    for(int i = 0;i<26;i++){
        t->child[i] = NULL;
    }
    t->is_end = false;
    t->freq = 0;
}
void construct(trie *root , string str){
    int ind ;
    cout<<str<<"\n";
    trie *t = root;
    for(int i =0 ;i<str.length();i++){
        ind = str[i] - 'a';
        if(!t->child[ind]){
            //cout<<"\n@@@@@@@@@\n";
            t->child[ind] = getNode();
            //(t->child[ind]->freq)++;
        }
        (t->child[ind]->freq)++;
        t = t->child[ind];
    }
    t->is_end = true;
}
void get_spf(trie *root){
    trie *t = root;char c;
    if(t->freq == 1){
        //cout<<"\n";
        return;
    }else{
        for(int i = 0 ;i <26;i++ ){
            if(t->child[i]){

                get_spf(t->child[i]);
                c = i+97;
                cout<<c<<"\t"<<t->freq<<"\n";

            }
            //cout<<"\n";
        }
    }
    //cout<<"\n";

}
int  main(){
    string s[4] = {"dog","dot","zebra","duck"};
    trie *root = getNode();

    for(int i = 0;i<4;i++){

        construct(root,s[i]);

    }
    get_spf(root);

}
