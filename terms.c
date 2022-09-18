#include<stdio.h>
int main(){
    int a,b,c=0;
    printf("Enter number\n");
    scanf("%d",&a);
    for(b=1;b<=a;b++){
        c+=b;
    }
    printf("%d\n",c);
    return 0;
}