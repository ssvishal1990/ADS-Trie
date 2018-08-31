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
        //cout<<"\n@@@@@@@@         \n"<<i;
        if(root->child[i]){
            return 0;
        }
    }
    return 1;
}
void delete1(trie *root, string str,int s){

    if(s>=str.length()){
        return;
    }else{
        int ind = str[s] - 'a';
        trie *t = root;
        if(t->child[ind]){
            delete1(t->child[ind],str,s+1);
        }
        if(check_leaf(t->child[ind])){
            t->child[ind] = NULL;
            delete(t->child[ind]);

            cout<<"DELETED \t"<<str[s]<<"\n";

        }else{

        }
    }
}
void lpm(trie *root , string str2){
    trie *t = root;
    int ind;
    string s1;

    int cf = 0,i,j=0;
    char c;
    for(i = 0;i<str2.length();i++){
        ind = str2[i] - 'a';
        if(t->child[ind]){
            //c = str2[i];
            char x[2] ;
            x[0] = str2[i];
            x[1] = '\0';
            s1.append((const char*)&x);
            //cout<<x;
            t = t->child[ind];
        }

    }
    if(t->is_end){
        cout<<s1<<"\n";
    }else
        cout<<"empty";
    /*

    if(i>=str2.length()){
        cout<<s1<<"\n";
    }else{
        cout<<"empty\n";

    }*/
}
int main(){
    string s1 = "are";
    string s2 = "area";
    string s3 = "base";
    string s4 = "cat";
    string s5 = "cater";
    string s6 = "children";
    string s7 = "basement";
    trie *t1 = getNode();
    insert1(t1,s1);
    insert1(t1,s2);
    insert1(t1,s3);
    insert1(t1,s4);
    insert1(t1,s5);
    insert1(t1,s6);
    insert1(t1,s7);
    //cout<<"enter string\t";
    //cin>>s1;
    //cout<<s1<<"\n";
    //delete1(t1,s3,0);
    //delete1(t1,s4,0);
    //delete1(t1,s5,0);
    lpm(t1,"caterer");
    if(search1(t1,s3) && search1(t1,s7)){
        cout<<"FOUND";
    }else{
        cout<<" not FOUND";
    }
    return 0;
}
