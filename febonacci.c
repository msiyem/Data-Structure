#include<stdio.h>
int febo(int n){
    if(n==0 || n==1) return n;
    return febo(n-1)+febo(n-2);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",febo(n));
}