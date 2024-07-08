#include<stdio.h>
void merge_sort(int a[],int t[],int l,int h){
   if(l==h) return;
   int mid=(l+h)/2;
   merge_sort(a,t,l,mid);
   merge_sort(a,t,mid+1,h);
   int i,j,k;
   for(i=l,j=mid+1,k=l; k<=h; k++){
    if(i>mid) t[k]=a[j++];
    else if(j>h) t[k]=a[i++];
    else if(a[i]<=a[j]) t[k]=a[i++];
    else if(a[i]>=a[j]) t[k]=a[j++];
   }
   for(k=l; k<=h; k++) a[k]=t[k];
}
int main(){
    int a[]={5,8,7,1,2,4,9,3,6};
    int size=sizeof(a)/sizeof(a[0]);
    int t[size];
    merge_sort(a,t,0,size-1);
    printf("\n");
    for(int i=0; i<size; i++) printf("%d ",a[i]);
}