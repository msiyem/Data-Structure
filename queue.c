#include<stdio.h>
int max;
int queue[1000],front=-1,rear=-1;
void enqueue(int value){
    if(rear==max-1) printf("queue overflow!\n");
    else{
        front=0;
        rear++;
        queue[rear]=value;
    }
}
void dequeue(){
    if(front==-1 && rear==-1) printf("Sorry! Queue already empty!\n");
    else{
        front++;
        if(front>rear){
            front=-1;
            rear=-1;
        }
    }
}
void peek(){
     if(front==-1 && rear==-1) printf("Queue empty!\n");
     else printf("%d \n",queue[front]);
}
void display(){
    if(rear==-1) printf("\nqueue is empty\n");
    else{
        for(int i=front; i<=rear; i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}
int main(){
    max=5;
    enqueue(3);
    enqueue(5);
    enqueue(8);
    enqueue(7);
    enqueue(2);
    enqueue(4);
    peek();
    display();
    dequeue();
    peek();
    display();
}
