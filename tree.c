#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(struct node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
struct node *creatnode(int value){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *inserleft(struct node *root,int value){
    root->left=creatnode(value);
    return root->left;
}
struct node *inserright(struct node *root,int value){
    root->right=creatnode(value);
    return root->right;
}
int tree_sum(struct node *root){
    if(root==NULL) return 0;
    return tree_sum(root->left)+tree_sum(root->right)+root->data;
}
int tree_height(struct node *root){
    if(root == NULL) return 0;
    int leftheight=tree_height(root->left);
    int rightheight=tree_height(root->right);
    return (leftheight>rightheight? leftheight: rightheight)+1;
}

int main(){
    struct node *root=creatnode(1);
    inserleft(root,7);
    inserright(root,10);
    inserleft(root->left,17);
    inserright(root->left,5);
    inserright(root->right,100);
    inserleft(root->left->left,117);
    inserright(root->right->right,1000);
    printf("\ninorder traversal : \n");
    inorder(root);
    printf("\nreorder traversal : \n");
    preorder(root);
    printf("\npostorder traversal : \n");
    postorder(root);
    printf("\nsum of tree : ");
    int sum=tree_sum(root);
    printf("%d\n",sum);
    printf("total height in tree : ");
    int treeheight=tree_height(root);
    printf("%d\n",treeheight);
}

