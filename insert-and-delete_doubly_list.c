#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data ;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;
node *start=NULL;
node *stop=NULL;
void insert(int a,int pos){
    node *news =(node *)malloc(sizeof(node));
    news->data=a;
    if(pos>=0){
        if(start==NULL){
            if(pos==0){
                news->next=NULL;
                news->prev=NULL;
                start=news;
                stop=news;
            }
            else{
                printf("No position found\n");
            }
        }
        else if(start->next==NULL){
            if(pos==0){
                news->next=start;
                news->prev=NULL;
                start->prev=news;
                start=news;
            }
            else if(pos==1){
                start->next=news;
                news->next=NULL;
                news->prev=start;
                stop=news;
            }
            else{
                printf("The list has only one node\n");
            }
        }
        else{
            if(pos==0){
                news->next=start;
                start->prev=news;
                news->prev=NULL;
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
                    for(int i=0;i<pos-1;i++){
                        temp=temp->next;
                    }
                    news->next=temp->next;
                    news->prev=temp;
                    temp->next->prev=news;
                    temp->next=news;
                }
                else{
                    if(b+1==pos){
                        news->next=NULL;
                        news->prev=stop;
                        stop->next=news;
                        stop=news;
                    }
                    else{
                        printf("Location not found\n");
                    }
                }
            }
        }
    }
    else{
        printf("Location cannot be negative\n");
    }
}
void deletion(int pos){
    if(pos>=0){
        if(start==NULL){
            printf("The list is empty\n");
        }
        else{
            if(pos==0){
                node *temp=start;
                start=start->next;
                start->prev=NULL;
                temp->next=NULL;
                temp->prev=NULL;
                free(temp);
            }
            else{
            node *temp=start;
            int b=0,c=1;
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
                for(int i=0;i<pos-1;i++){
                    temp=temp->next;
                }
                if(temp->next==stop){
                    node *temps=stop;
                    stop=stop->prev;
                    stop->next=NULL;
                    temps->next=NULL;
                    temps->prev=NULL;
                    free(temps);
                }
                else{
                node *temps=temp->next;
                temps->next->prev=temp;
                temp->next=temps->next;
                temps->next=NULL;
                temps->prev=NULL;
                free(temps);
                }
            }
            else{
                printf("Position not found\n");
            }
        }
        }
    }
    else{
        printf("Location cannot be negative\n");
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
        printf("Continue addition y/n");
        scanf("%s",&c);
    }while(c=='y'||c=='Y');
    node *temp=start;
    for(temp=start;temp!=NULL;temp=temp->next){
        printf("%d\n",temp->data);
    }
    do{
        printf("Enter position to delete\n");
        scanf("%d",&a);
        deletion(a);
        printf("Continue deletion\n");
        scanf("%s",&c);
    }while(c=='y'||c=='Y');
    for(temp=start;temp!=NULL;temp=temp->next){
        printf("%d\n",temp->data);
    }
}