#include<stdio.h>
void swap(int *a,int *b){
    int tem=*a;
    *a=*b;
    *b=tem;
}

int pivot(int a[],int l,int h){
   int p=a[l];
   int i=l,j=h;
   while(i<=j){
    while(a[i]<=p){
        i++;
    }
    while(a[j]>p){
        j--;
    }
    if(i<j) swap(&a[i],&a[j]);
   }
   swap(&a[l],&a[j]);
   return j;

}
void quicksort(int a[], int l,int h){
    if(l<h){
        int loc=pivot(a,l,h);
        quicksort(a,l,loc-1);
        quicksort(a,loc+1,h);
    }
}
int main(){
    int a[]={5,6,4,2,1,3,7,9,8};
    
    quicksort(a,0,8);
    for(int i=0; i<9; i++){
        printf("%d ",a[i]);
    }
}