#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node;
int main(){
    node *start =(node *)malloc(sizeof(node));
    node n1,n2;
    n1.data=12;
    n2.data=23;
    n1.next=&n2;
    start=&n1;
    for(int i=0;i<2;i++){
        printf("%d\n",start->data);
        start=start->next;
    }
}