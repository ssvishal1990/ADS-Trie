#include<iostream>
#include<stdlib.h>
using namespace std;
void kmp(string s1, string s2){
    cout<<s1.length()<<"\n";
    int *a = new int[s2.length()];
    int i ,j=0 ;
    a[0] = 0;
    for(int i = 1 ;i <s2.length();i++){
        if(s2[i] == s2[j]){
            a[i] = j+1;
            j++;
        }else if(j==0 && s2[i] != s2[j]){
            a[i] = j;
        }else{
                j--;
                j = a[j];
                i--;
        }
    }
    j =0 ;
    /*
    for(i = 0 ;i <s2.length();i++){
        cout<<a[i]<<"\n";
    }*/
    for(i = 0 ;i <s1.length();i++){
        if(s1[i] == s2[j] ){
            cout<<j<<"\t"<<s1[i]<<"\t"<<s2[j]<<"\n";
            j++;
        }else{
            if(j>0){
                cout<<j<<"\t"<<s1[i]<<"\t"<<s2[j]<<"\n";
                j = a[j-1];
                i--;
            }
        }
        if(j == s2.length()){
            //cout<<j<<"\n";
            cout<<"\n PATTERN ENCOUNTERED AT::\t"<<i-s2.length()<<"\n";
            j = 0;
        }
    }
}
int main(){
    string s1, s2;
    //cout<<"enter string:\n";
    cin>>s1;
    //cout<<"\n ENTER PATTERN\n";
    cin>>s2;
    kmp(s1,s2);
    return 0;
}
