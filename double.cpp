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
int main(){
    char c;
    node *temps=start;
    do{
        insert();
        cout<<"Whether to add more node\n";
        cin>>c;
    }while(c=='Y'||c=='y');
    cout<<"Using start\n";
    for(temps=start;temps!=NULL;temps=temps->next){
        cout<<temps->data<<endl;
    }
    cout<<"Using stop\n";
    for(temps=stop;temps!=NULL;temps=temps->prev){
        cout<<temps->data<<endl;
    }
}