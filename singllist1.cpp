#include<iostream>
using namespace std;
class node {
    public:
    int data;
    node *next;
};
node *start=NULL;
void insert(){
    node *news=new node;
    cout<<"Enter number\n";
    cin>>news->data;
    news->next=NULL;
    if(start==NULL){
        start=news;
    }
    else{
        news->next=start;
        start=news;
    }
}
int main(){
    char c;
    node *temp=start;
    do{
        insert();
        cout<<"Add node y/n\n";
        cin>>c;
    }while(c=='Y'||c=='y');
    for(temp=start;temp!=NULL;temp=temp->next){
        cout<<temp->data<<endl;
    }
}