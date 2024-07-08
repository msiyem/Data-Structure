#include<stdio.h>
int size=0;

void swap(int *a, int *b){
    int temp=*a;
    *a = *b;
    *b = temp;

}
void Minheapify(int arr[], int size ,int i){
    if(size==1) printf("only one element in heap\n");
    else{
        int min=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<size && arr[left]);
    }
}