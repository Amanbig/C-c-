#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *start=NULL;
typedef struct Node node;
void insert(int a,int pos){
    node *news=(node *)malloc(sizeof(node));
    news->data=a;
    news->next=NULL;
    if(pos>=0){
        if(start==NULL){
            if(pos==0){
                start=news;
                news->next=NULL;
            }
            else{
                printf("The list is empty\n");
            }
        }
        else if(start->next==NULL){
            if(pos==0){
                news->next=start;
                start=news;
            }
            else if(pos==1){
                start->next=news;
                news->next=NULL;
            }
            else{
                printf("The list has only one node\n");
            }
        }
        else{
            if(pos==0){
                news->next=start;
                start=news;
            }
            else{
                int b=0,c=1;
                node *temp=start;
                while(temp->next!=NULL){
                    b++;
                    temp=temp->next;
                    if(b==pos){
                        c=1;
                        break;
                    }
                    else{
                        c=0;
                    }
                }
                if(c==1){
                    temp=start;
                    for(int i=0;i<=pos-1;i++){
                        temp=temp->next;
                    }
                    news->next=temp->next;
                    temp->next=news;
                }
                else{
                    if(b+1==pos){
                        news->next=NULL;
                        temp->next=news;
                    }
                    else{
                    printf("Location not found\n");
                    }
                }
            }
        }
    }
    else{
        printf("Postion cannot be negative\n");
    }
}
void deletion(int pos){
    if(pos>=0){
        if(start==NULL){
            printf("The list is already empty\n");
        }
        else{
            if(pos==0){
                node *temp=start;
                start=start->next;
                temp->next=NULL;
                free(temp);
            }
            else{
            int b=0,c=1;
            node *temp=start;
            while(temp->next!=NULL){
                b++;
                temp=temp->next;
                if(b==pos-1){
                    c=1;
                    break;
                }
                else{
                    c=0;
                }
            }
            if(c==1){
                temp=start;
                for(int i=0;i<pos-1;i++){
                    temp=temp->next;
                }
                if(temp->next->next==NULL){
                    node *temps=temp->next;
                    temp->next->next=NULL;
                    temp->next=NULL;
                    free(temps);
                }
                else{
                node *temps=temp->next;
                temp->next=temp->next->next;
                temps->next=NULL;
                free(temps);
                }
            }
            else{
                printf("Location not found\n");
            }
        }}
    }
    else{
        printf("Position cannot be negative\n");
    }
}
int main(){
    char c;
    int a,b;
    do{
        printf("Enter number\n");
        scanf("%d",&a);
        printf("Enter position\n");
        scanf("%d",&b);
        insert(a,b);
        printf("Continue addition y/n\n");
        scanf("%s",&c);
    }while(c=='y'||c=='Y');
    node *temp=start;
    for(temp=start;temp!=NULL;temp=temp->next){
        printf("%d\n",temp->data);
    }
    do{
        printf("Enter postion\n");
        scanf("%d",&a);
        deletion(a);
        printf("Continue deletion y/n\n");
        scanf("%s",&c);
    }while(c=='Y'||c=='y');
    for(temp=start;temp!=NULL;temp=temp->next){
        printf("%d\n",temp->data);
    }
}