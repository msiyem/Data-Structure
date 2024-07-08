#include<stdio.h>
void insert_sort(int a[],int h){
for(int i=1; i<h; i++){
 int key=a[i];
 int j=i-1;
 while(j>=0 && key<a[j]){
    a[j+1]=a[j];
    j--;
 }
 a[j+1]=key;
}
for(int i=0; i<h; i++) printf("%d ",a[i]);
}
int main(){
    int a[]={2,4,8,7,6,1,3};
    int size=sizeof(a)/sizeof(a[0]);
    printf("\n");
    insert_sort(a,size);

}
