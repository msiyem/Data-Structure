#include<stdio.h>
int max;
int stack[10000];
int top=-1;
void stack_push(){
    if(top==max-1) printf("stack overflow!\n");
    else {
        int x;
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void stack_pop(){
    if(top==-1) printf("stack in empty!\n");
    else{
        top--;
    }
}
void stack_top(){
    if(top==-1) printf("stack is empty!\n");
    else {
        printf("%d \n",stack[top]);
    }
}
void stack_display(){
     if(top==-1) printf("stack in empty!\n");
     else {
        for(int i=0; i<=top; i++) printf("%d ",stack[i]);
     }
}
int main(){
    printf("Enter number of element in stack:");
    scanf("%d",&max);
    for(int i=0; i<max; i++) stack_push();
    stack_top();
    stack_pop();
    stack_top();
}