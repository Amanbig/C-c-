#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(){
        next=NULL;
    }
};
class stack{
    node *start=NULL;
    public:
    void push();
    void pop();
    void show();
};
void stack::push(){
    node *news=new node;
    cout<<"Enter data\n";
    cin>>news->data;
    if(news==NULL){
        cout<<"Overflow\n";
    }
    else if(start==NULL){
        start=news;
        news->next=NULL;
    }
    else{
        node *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=news;
        news->next=NULL;
    }
}
void stack::pop(){
    if(start==NULL){
        cout<<"The stack is already empty\n";
    }
    else{
        node *temp=start;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        node *asd=temp->next;
        temp->next=NULL;
        delete asd;
    }
}
void stack::show(){
    if(start==NULL){
        cout<<"The stack is already empty\n";
    }
    else{
        node *temp=start;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
}
int main(){
    stack s;
    s.push();
    s.push();
    s.show();
    s.pop();
    s.show();
}