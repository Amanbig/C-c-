#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
node *start=NULL;
void insert(){
    node *news=new node;
    news->next=NULL;
    cout<<"Enter number\n";
    cin>>news->data;
    if(start==NULL){
        start=news;
    }
    else{
        node *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=news;
    }
}
void deletion(int a){
    node *temps=start;
    if(a>=0){
        if(start==NULL){
            cout<<"The list is already empty\n";
        }
        else{
            int b=0;
            bool c=true;
            while(temps->next!=NULL){
                b++;
                temps=temps->next;
                if(b==(a-1)){
                    c=true;
                    break;
                }
                else{
                    c=false;
                }
            }
            if(c){
                temps=start;
                for(int i=1;i<a-1;i++){
                    temps=temps->next;
                }
                node *asd;
                asd=temps->next;
                temps->next=temps->next->next;
                asd->next=NULL;
                delete asd;
            }
            else{
                cout<<"Location not found\n";
            }
        }
    }
    else{
        cout<<"Location cannot be negative\n";
    }
}
int main(){
    char c;
    do{
        insert();
        cout<<"Add node or not y/n\n";
        cin>>c;
    }while(c=='y'||c=='Y');
    node *temp=start;
    for(temp=start;temp!=NULL;temp=temp->next){
        cout<<temp->data<<endl;
    }
    int a;
    do{
        cout<<"Enter position to delete\n";
        cin>>a;
        deletion(a);
        cout<<"Continue deletion\n";
        cin>>c;
    }while(c=='y'||c=='Y');
    cout<<"Now the list is\n";
    for(temp=start;temp!=NULL;temp=temp->next){
        cout<<temp->data<<endl;
    }
}