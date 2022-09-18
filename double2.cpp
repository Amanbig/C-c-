#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *prev;
    node(){
        next=NULL;
        prev=NULL;
    }
};
node *start=NULL;
node *stop=NULL;
void insert(){
    node *news=new node;
    news->next=NULL;
    cout<<"Enter number\n";
    cin>>news->data;
    if(start==NULL){
        start=news;
        news->next=NULL;
        news->prev=NULL;
        stop=news;
    }
    else{
        node *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=news;
        news->prev=temp;
        news->next=NULL;
        stop=news;
    }
}
void deletion(){
    if(start==NULL){
        cout<<"No match\n";
    }
    else{
        node *temp=start;
        node *temps=stop;
        cout<<"Enter location to delete\n";
        int a;
        cin>>a;
        for(int i=0;i<a-1;i++){
            temp=temp->next;
        }
        temps=temp->next;
        temp->next=temps->next;
        temps->next->prev=temp;
        temps->next=NULL;
        delete temps;
    }
}
int main(){
    char c;
    node *temp=start;
    do{
        insert();
        cout<<"Enter y/n\n";
        cin>>c;
    }while(c=='Y'||c=='y');
    cout<<"H\n";
    deletion();
    for(temp=start;temp!=NULL;temp=temp->next){
        cout<<temp->data<<endl;
    }
}