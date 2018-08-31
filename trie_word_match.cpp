#include<iostream>
#include<stdlib.h>
using namespace std;
const int alpha = 26 , m = 3 , n =3 ;
typedef struct trie{
    struct trie *child[alpha];
    bool is_end;
}trie;
typedef struct stack1{
    char c;
    int i, j;
}stack1;


class dict{
private:
    trie *root;
    char a[m][n];
    int rc,cc,top,i ,j;
    stack1 *s;
public:
    trie* getNode(){
        trie *t = new trie();
        for(int i = 0;i<26;i++){
            t->child[i] = NULL;
        }
        t->is_end = false;
    }
    void construct(trie *root, string str){
        int ind;
        trie *t = root;
        for(int i = 0;i<str.length();i++){
            ind  = str[i] - 'a';
            if(!t->child[ind]){
                t->child[ind] = getNode();
            }
            t = t->child[ind];
        }
        t->is_end = true;
        //cout<<"\n"<<str<<"\n";
    }
    void construct_trie(string str){
        construct(root,str);
    }
    dict(int n,string str){
        top = -1;
        i =j=0;
        rc = cc = n;
        /*
        a = (char **)malloc(n*sizeof(char));
        for(int i = 0 ;i<n;i++){
            a[i] = (char *)malloc(n*sizeof(char));
        }*/

        root = getNode();
        int k =0 ;
        for(int i =0 ;i<3;i++){
            for(int j =0 ;j<3;j++){
                a[i][j] = str[k];
                k++;
            }
        }/*
                for(int i =0 ;i<3;i++){
            for(int j =0 ;j<3;j++){
                //a[i][j] = str[k];
                //k++;
                cout<<a[i][j]<<"\t";
            }
            cout<<"\n";
        }*/

        //cout<<a[0][0];
    }
    void  push_adjacent(stack1 *s){
        if(i-1>=0 && j-1>=0){
            s[++top].c = a[i-1][j-1];
            s[top].i = i-1;
            s[top].j = j-1;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";
        }
        if(i-1>=0){
            s[++top].c = a[i-1][j];
            s[top].i = i-1;
            s[top].j = j;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";
        }
        if(i-1>=0 && j+1<cc ){
            s[++top].c = a[i-1][j+1];
            s[top].i = i-1;
            s[top].j = j+1;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";
        }
        if(j-1>=0){
            s[++top].c = a[i][j-1];
            s[top].i = i;
            s[top].j = j-1;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";

        }
        if(j+1<cc){
            s[++top].c = a[i][j+1];
            s[top].i = i;
            s[top].j = j+1;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";
        }
        if(i+1<rc && j-1 >= 0){
            s[++top].c = a[i+1][j-1];
            s[top].i = i+1;
            s[top].j = j-1;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";
        }
        if(i+1<rc){
            s[++top].c = a[i+1][j];
            s[top].i = i+1;
            s[top].j = j;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";
        }
        if(i+1<rc && j+1 < cc){
            s[++top].c = a[i+1][j+1];
            s[top].i = i+1;
            s[top].j = j+1;
               //        cout<<s[top].c<<"\t top"<<top<<"\n";
            //cout<<"i       "<<s[top].i<<"\tj    "<<s[top].j<<" \n";
        }

    }
    void find_words(){
        trie *t = root;

        s = new stack1[100];

        s[++top].c = a[0][0];
        //cout<<"\n @@@@@@@@ \n";
        s[top].i =0;
        s[top].j =0;

        while(top != -1 ){

            if(t->child[(s[top].c)-'a']){
                t = t->child[(s[top].c)-'a'];
                //if(t->is_end)break;
                cout<<s[top].c;
                i = s[top].i;
                j = s[top].j;
                //top--;
                //cout<<"i       "<<i<<"\tj    "<<j<<" \n";
                push_adjacent(s);
                //t = t->child[(s[top].c)-'a'];
            }else{
                //cout<<s[top].c<<"\t top"<<top<<"\n";
                top--;
            }

        }
        delete(s);
        //cout<<"\n @@@@@@@ \n";

    }

    ~dict(){
        //cout<<"\n\n@@@\n";
        //free(s);
        //cout<<"\n!!\n";
        free(root);

    }

};
int main(){
    dict d(3,"gizuekqse");
    d.construct_trie("geeks");
    d.construct_trie("for");
    d.construct_trie("go");
    d.construct_trie("quiz");
    d.find_words();
    //cout<<"\n #### \n";
    return 0;
}
