#include<stdio.h>
int fac(int a){
    if(a==0||a==1)
    return 1;
    else
    return a*fac(a-1);
}
int main(){
    int a;
    printf("Enter number \n");
    scanf("%d",&a);
    printf("%d",fac(a));
    return 0;
}