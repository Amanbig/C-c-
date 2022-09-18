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
node *start=NULL;
void insert(int a,int pos){
    node *news=new node;
    news->data=a;
    if(pos>=0){
    if(start==NULL){
        if(pos==0){
            start=news;
            news->next=NULL;
        }
        else if(pos>=1){
            cout<<"List is empty\n";
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
            cout<<"This list has only one nodes\n";
        }
    }
    else{
        if(pos==0){
            news->next=start;
            start=news;
        }
        else{
            int c=0;
            bool b=true;
            node *temp=start;
            while(temp->next!=NULL){
                c++;
                temp=temp->next;
                if(c==pos){
                    b=true;
                    break;
                }
                else{
                    b=false;
                }
            }
            if(b){
                temp=start;
                for(int i=1;i<=pos-1;i++){
                    temp=temp->next;
                }
                news->next=temp->next;
                temp->next=news;
            }
            else{
                cout<<"Position not found\n";
            }
        }}
    }
    else{
            cout<<"The position cannot be negative\n";
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
                for(int i=0;i<a-1;i++){
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
    int a,b;
    do{
        cout<<"Enter number\n";
        cin>>a;
        cout<<"Enter position to insert\n";
        cin>>b;
        insert(a,b);
        cout<<"Add another node y/n\n";
        cin>>c;
    }while(c=='y'||c=='Y');
    node *temps=start;
    cout<<"The elements are:-\n";
    for(temps=start;temps!=NULL;temps=temps->next){
        cout<<temps->data<<endl;
    }
    do{
        cout<<"Enter position to delete\n";
        cin>>a;
        deletion(a);
        cout<<"Continue deletion\n";
        cin>>c;
    }while(c=='y'||c=='Y');
    cout<<"Now the list is\n";
    for(temps=start;temps!=NULL;temps=temps->next){
        cout<<temps->data<<endl;
    }
}