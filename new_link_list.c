#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void creatnode(int value) {
struct node *newnode =malloc(sizeof(struct node));
newnode->data=value;
newnode->next=NULL;

if(head==NULL) head=newnode;
else{
    struct node *temp=head;
    while(temp->next!= NULL){

        temp=temp->next;
    }
    temp->next=newnode;
}

}
void display(){
    struct node *ptr=head;
    if(ptr==NULL){
        printf("empty link list!");
    }
    else{
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;

        }
    }
}
void first_remove(){
    struct node *temp=head;
    head=head->next;
    free(temp);
}
void remove_by_key(int key){
    struct node *current=head;
    struct node *previous=NULL;
    if(head==NULL) return;
    while(current!=NULL && current -> data!= key){
        previous=current;
        current=current->next;
    }
    if(current==NULL) return;
    else{
        previous->next=current->next;
        
    }
    free(current);
}
void insert_after_key(int key,int value){

    struct node *current=head;
    if(head==NULL) return;
    while(current != NULL && current -> data != key){
        current=current->next;
    }
    if(current == NULL) return;
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=current->next;
    current->next= newnode;
}
void sort(){
    struct node *ptr1;
    struct node *ptr2;
    int temp;
    for(ptr1=head; ptr1->next!=NULL; ptr1=ptr1->next){
        for(ptr2=ptr1->next; ptr2!=NULL; ptr2=ptr2->next){
            if(ptr1->data>ptr2->data){
                temp=ptr2->data;
                ptr2->data=ptr1->data;
                ptr1->data=temp;
            }

        
    }
    }
}
void reverse(){
    struct node *prevous=NULL;
    struct node *current=head;
    struct node *next=NULL;
    while(current != NULL){
         next=current->next;
         current->next=prevous;
         prevous=current;
         current=next;
    }
    head=prevous;
}
int main(){
    creatnode(1);
    creatnode(2);
    creatnode(5);
    creatnode(3);
    creatnode(4);
    first_remove();
    display();
    printf("\n after delate : 3 \n");
    remove_by_key(3);
    display();
    printf("\n after insert : 2 \n");
    insert_after_key(2,3);
    insert_after_key(3,4);
    display();
    printf("\n after sort : \n");
    sort();
    display();
    printf("\n after sort : \n");
    reverse();
    display();
}
