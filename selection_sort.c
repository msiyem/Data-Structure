#include<stdio.h>
void s_sort(int a[],int h){
    for(int i=0; i<=h-1; i++){
        int min=i;
        for(int j=i+1; j<=h; j++){
            if(a[j]<=a[min]) min=j;
        }
        if(min!=i){
            int tem=a[i];
            a[i]=a[min];
            a[min]=tem;
        }
    }
    for(int i=0; i<=h; i++) printf("%d ",a[i]);
}
int main(){
    int a[]={5,3,4,7,2,6,1,3,8,9};
    int size=sizeof(a)/sizeof(a[0]);
    printf("\n");
    s_sort(a,size-1);
    
}