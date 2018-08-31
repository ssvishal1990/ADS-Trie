#include<iostream>
#include<stdlib.h>
using namespace std;
const int a_size = 26;
typedef struct trie{
    struct trie *child[a_size];
    bool is_end;
}trie;
trie* getNode(){
    trie *t = new trie();
    for(int i = 0;i<26;i++){
        t->child[i] = NULL;
    }
    t->is_end = false;
}
void insert1(trie *root , string str){
    trie *pnode = root;
    int index;
    for(int i = 0 ;i <str.length();i++){
        index = str[i] - 'a';
        if(!pnode->child[index]){
            pnode->child[index] = getNode();
        }
        pnode = pnode->child[index];
    }
    pnode->is_end = true;
}
bool search1(trie *root, string s2){
    int index;
    trie *pnode = root;
    for(int i = 0 ; i<s2.length();i++){
        index = s2[i] - 'a';
        if(!pnode->child[index]){
                return false;
        }
        pnode = pnode->child[index];

    }
    return (pnode != NULL && pnode->is_end);
}
int check_leaf(trie *root){
    for(int i = 0 ;i <26;i++){
        if(root->child[i]){
            return 0;
        }
    }
    return 1;
}
void delete1(trie *root, string str,int s){
    if(s == str.length() || s>str.length()){
        return;
    }else{
            int ind;
            trie *temp, *t = root;
            ind = str[s] - 'a';
            /*
            if(t->child[str[s+1]-1]->is_end == true){
                temp = t->child[ind];
                t->child[ind] = NULL;
                free(temp);
                if(check_leaf(t)){
                    t->is_end = true;
                }
            }else{

            }*/
            if(!check_leaf(t->child[ind])){
                delete1(t->child[ind],str,s+1);
            }else{
                temp = t->child[ind];
                t->child[ind] = NULL;
                free(temp);
            }


    }

}
int main(){
    string s1 = "hello";
    string s2 = "world";
    string s3 = "thus";
    string s4 = "is";
    string s5 = "fucked";
    trie *t1 = getNode();
    insert1(t1,s1);
    insert1(t1,s2);
    insert1(t1,s3);
    insert1(t1,s4);
    insert1(t1,s5);

    if(search1(t1,s1)){
        cout<<"FOUND";
    }else{
        cout<<" not FOUND";
    }
    return 0;
}
