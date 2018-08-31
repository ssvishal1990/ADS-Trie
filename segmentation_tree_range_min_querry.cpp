#include<iostream>
#include<stdlib.h>
using namespace std;
int min1(int a , int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
void construct(int *i, int *st, int low, int high , int pos){
    if(low == high){
        st[pos] = i[low];
        return;
    }else{
        int mid = (low + high)/2;
        construct(i,st,low,mid,2*pos+1);
        construct(i,st,mid+1,high,2*pos+2);
        st[pos] = min1(st[2*pos+1],st[2*pos+2]);
    }
}
int range_querry(int *st, int low , int high , int ql, int qh,int pos){
    if(ql<=low && qh >= high){
        return st[pos];
    }else if(ql>high || qh<low){
        return INT_MAX;
    }else{
        int mid = (low + high)/2;
        return min1(range_querry(st,low,mid,ql,qh,2*pos+1),range_querry(st,mid+1,high,ql,qh,2*pos+2));
    }
}
int main(){
    int n = 4, cp =1;
    int arr[] = {-1,2,4,0};
    while(cp !=n || cp < n){
        cp *= 2;
    }
    //cout<<cp<<"\n";
    int *st = (int *)malloc(((2*cp)-1)*sizeof(int));
    construct(arr,st,0,3,0);
    for(int i = 0;i<(2*cp -1);i++){
        cout<<st[i]<<"\n";
    }
    cout<<"\n ----------------- \n";
    if(range_querry(st,0,(2*cp-2),0,3,0) == INT_MAX){
        cout<<"WRONG SEGMENT\n";
    }else{
        cout<<range_querry(st,0,(2*cp-2),0,3,0);
    }
}
