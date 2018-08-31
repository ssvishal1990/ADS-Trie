#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
typedef struct tree{
    int data;
    int height;
    struct tree *right,*left;
}node;
node* left_left(node *t){
    node *temp = t;
    node *lct = t->left,*rct = lct->right;
    t = lct;
    t->right = temp;
    temp->left = rct;

    return t;
}
node* left_right(node *t){

    node *temp = t,*lct = t->left,*rct = lct->right;
    //cout<<" @@@@@@@22";
    t->left = rct;
    lct->right = rct->left;
    rct->left = lct;
    t = left_left(t);

    return t;
}
node* right_right(node *t){

    node *temp = t ,*rct = t->right,*lct = rct->left;
    t = rct;
    t->left = temp;
    temp->right = lct;
    /*if(t == NULL){
        cout<<"setting null";
    }*/

    return t;
}
node* right_left(node *t){
    node *rct = t->right,*lct = rct->left,*temp = t;
    t->right = lct;
    rct->left = lct->right;
    lct->right = rct;
    t = right_right(t);


    return t;
}
int set_height(node *t){
    if(t == NULL){
        return -1;
    }else{
        int lh = set_height(t->left);
        int rh = set_height(t->right);
        if(lh > rh){
            return lh+1;
        }else{
            return rh+1;
        }
    }
}
node* insert1(node *root,int num){
    if(root == NULL){

        root = new node();
        root->left = NULL;
        root->right = NULL;
        root->height = 0;
        root->data = num;
    }else{
        if(root->data < num){
            root->right = insert1(root->right,num);
        }else if(root->data > num)
            root->left = insert1(root->left, num);
        else{
            return root;
        }
        node *t = root;
        int bal = set_height(t->left) - set_height(t->right);
        if(bal > 1){
                if(set_height(t->left->left) > set_height(t->left->right)){
                    //cout<<" llllll ";
                    t = left_left(t);
                }else{
                   // cout<<" lrlrlrlr ";
                    t->left = right_right(t->left);
                    t = left_left(t);

                }
        }
        if(bal < -1){
            if(set_height(t->right->left)<set_height(t->right->right)){
                cout<<" rrrrr ";
                t = right_right(t);
            }else{
                cout<<" rlrlrl ";
                t->right = left_left(t->right);
                t = right_right(t);
                //t =right_left(t);
            }
        }
    root  = t;

    }
    return root;
}

void print(node *root){
    if(root ==  NULL){
        return;
    }else{
       //cout<<root->data<<"-> ";//        "<<root->height<<"\n";
        //root->height = set_height(root);
        print(root->left);
        cout<<root->data<<"-> height of this node         "<<root->height<<"\n";
        //root->height = set_height(root);
        print(root->right);
        //cout<<root->data<<"-> height of this node         "<<root->height<<"\n";

    }
}

int main(){
    //srand(time(NULL));
    node *t = NULL;
    int x;
    int i = 0;
    while(i<10){
        cin>>x;/*
        if(i>5){
            x = x%10;
            t = insert1(t,x);
        }*/
        if(x<100){
            t = insert1(t,x);
            i++;
        }
    }
    print(t);

    return 0 ;
}

