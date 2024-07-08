#include<stdio.h>
int c_queue[100],max,rear=-1,front=-1;
void enqueue(int value){
    if(front==(rear+1)%max) printf("Queue overflow!\n");
    else{
        if(front==-1 && rear==-1){
            front=rear=0;   
            c_queue[rear]=value;
        }
        else{
            rear=(rear+1)%max;
            c_queue[rear]=value;
            
        }
    }
}
void dequeue(){
    if(rear==-1 && front==-1) printf("Queue is empty!\n");
    else{
        if(rear==front) rear=front=-1;
        else{
            front=(front+1)%max;
        }
    }
}
void peek(){
    if(front==-1) printf("Queue is empty!\n");
    else printf("front : %d \n" , c_queue[front]);
}
void display(){
    if(front==rear==-1) printf("Queue is empty!\n");
    else{
        for(int i=front; i!=rear; i=(i+1)%max){
            printf("%d ",c_queue[i]);
        }
        printf("%d \n",c_queue[rear]);
    }
}
int main(){
    max=5;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    peek();
    display();
    dequeue();
    peek();
    enqueue(6);
    display();
    
}