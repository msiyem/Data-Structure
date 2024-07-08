#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left, *right;

};
struct node *creatnode(int value){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node *root,int value){
    if(root==NULL) return creatnode(value);
    if(root->data>value) root->left=insert(root->left,value);
    else root->right=insert(root->right,value);
    return root;
}
void inorder(struct node *root){
    if(root==NULL) return;
  
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
struct node *minvaluenode(struct node *root){
    struct node *current=root;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current;
}

struct node *deletnode(struct node *root,int key){
    if(root==NULL) return root;

    if(key<root->data){
        root->left = deletnode(root->left,key);
    }
    else if(key>root->data){
        root->right= deletnode(root->right,key);
    }
    else{
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp= root->left;
            free(root);
            return temp;
        }
        struct node *temp=minvaluenode(root->right);
        root->data=temp->data;
        root->right=deletnode(root->right,temp->data);
        
    }
    return root;
}

int main(){
    struct node *root=NULL;
    root=insert(root,8);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,7);
    root=insert(root,10);
    root=insert(root,14);
    root=insert(root,4);
    printf("\ninorder traversal : \n");
    inorder(root);
    printf("\nafter delet 3 : \n");
    deletnode(root,3);
    inorder(root);

}

