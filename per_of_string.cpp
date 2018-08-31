#include<iostream>
#include<math.h>
using namespace std;
void swap(char *a , char *b){
    char t;
    t = *a;
    *a = *b;
    *b = t;
}
void permute(string str,int s, int e){
    if(s == e){
        cout<<str<<endl;
    }else{
        for(int i = s;i<=e;i++){
            swap(&str[i],&str[s]);
            permute(str,s+1,e);
            swap(&str[i],&str[s]);
        }
    }
}
int main(){
    string str;
    cin>>str;
    //cout<<str.length();
    permute(str,0,str.length()-1);
    return 0;
}
