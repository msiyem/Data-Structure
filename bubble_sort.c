#include<stdio.h>
void bubble_sort(int a[],int h){
    int i,j,tem;
    for(i=0; i<h-1; i++){
        for(j=0; j<h-i-1; j++){
            if(a[j+1]<a[j]){
                tem=a[j+1];
                a[j+1]=a[j];
                a[j]=tem;
            }
        }
    }
    for(i=0; i<h; i++) printf("%d ",a[i]);

}
int main(){
    int a[]={5,6,4,2,7,1,3};
    int size=sizeof(a)/sizeof(a[0]);
    printf("\n");
    bubble_sort(a,size);
}