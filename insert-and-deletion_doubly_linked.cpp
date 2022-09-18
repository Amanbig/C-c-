#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node *prev;
};
node *start=NULL;
node *stop=NULL;
void insert(int a,int pos){
    node *news=new node;
    news->data=a;
    if(pos>=0){
        if(start==NULL){
            if(pos==0){
                start=news;
                news->next=NULL;
                news->prev=NULL;
                stop=news;
            }
            else{
                cout<<"list is empty\n";
            }
        }
        else if(start->next==NULL){
            if(pos==0){
                news->next=start;
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
                cout<<"The list is only one\n";
            }
        }
        else{
        if(pos==0){
            news->next=start;
            news->prev=NULL;
            start->prev=news;
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
                news->prev=temp;
                temp->next->prev=news;
                temp->next=news;
            }
            else{
                if(c+1==pos){
                    news->next=NULL;
                    news->prev=stop;
                    stop->next=news;
                    stop=news;
                }
                else{
                cout<<"Position not found\n";
                }
            }
        }}
    }
    else{
        cout<<"Location cannot be negative\n";
    }
}
void deletion(int a){
    if(a>=0){
        if(start==NULL){
            cout<<"The list is already empty\n";
        }
        else{
            if(a==0){
                node *temp=start;
                start=start->next;
                start->prev=NULL;
                temp->next=NULL;
                temp->prev=NULL;
                delete temp;
            }
            else{
                node *temp=start;
            int b=0;
            bool c=true;
            while(temp->next!=NULL){
                b++;
                temp=temp->next;
                if(b==a){
                    c=true;
                    break;
                }
                else{
                    c=false;
                }
            }
            if(c){
                temp=start;
                for(int i=0;i<a-1;i++){
                    temp=temp->next;
                }
                if(temp->next==stop){
                    node *temps=stop;
                    stop=stop->prev;
                    stop->next=NULL;
                    temps->next=NULL;
                    temps->prev=NULL;
                    delete temps;
                }
                else{
                node *temps=temp->next;
                temps->next->prev=temp;
                temp->next=temps->next;
                temps->next=NULL;
                temps->prev=NULL;
                delete temps;
                }
            }
            else{
                cout<<"Location not found\n";
            }
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