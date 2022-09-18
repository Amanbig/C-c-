#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *prev;
    node *next;
    node(){
        prev=NULL;
        next=NULL;
    }
};
node *start=NULL;
node *stop=NULL;
void insert(){
    node *news=new node;
    cout<<"Enter number\n";
    cin>>news->data;
    if(start==NULL){
        start=news;
        news->next=NULL;
        news->prev=NULL;
        stop=news;
    }
    else{
        node *temp=stop;
        while(temp->prev!=NULL){
            temp=temp->prev;
        }
        temp->prev=news;
        news->prev=NULL;
        news->next=temp;
        start=news;
    }
}
int main(){
    char c;
    node *temp;
    do{
        insert();
        cout<<"Add node y/n\n";
        cin>>c;
    }while(c=='y'||c=='Y');
    for(temp=start;temp!=NULL;temp=temp->next){
        cout<<temp->data<<endl;
    }
}