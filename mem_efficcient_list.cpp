#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
using namespace std;
typedef struct node{
    int data;
    struct node *nptx;
}node;
node* xor1(node *a, node *b){
    return (node *) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
void insert1(node **head, int num){
    node *n;
    n = new node();
    n->data = num;
    n->nptx = xor1(*head,NULL);
    if(*head != NULL){
        node *next = xor1((*head)->nptx,NULL);
        (*head)->nptx = xor1(n,next);
    }
    *head = n;
}
void print(node **head){
    node *curr,*prev,*next;
    curr = *head;
    prev = NULL;
    while(curr != NULL){
        cout<<curr->data<<"\t";
        next = xor1(curr->nptx,prev);
        prev = curr;
        curr = next;
    }
}
int main(){
    int x = 10;
    node *head;
    head = NULL;
    for(int i = 0 ;i <4;i++){
        insert1(&head,x);
        x = x*10;
    }
    print(&head);
    return 0;
}
