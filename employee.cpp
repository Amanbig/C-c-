#include<iostream>
#include<iomanip>
using namespace std;
class address{
    public:
    int house;
    string village;
    string city;
    string state;
    int pin;
};
class employee{
    public:
    int no;
    string name;
    string father;
    string depart;
    int joining;
    int retire;
    address a;
};
class Node{
    public:
    employee e;
    Node *next;
};
class linkedlist{
    public:
    Node *start,*end;
    linkedlist(){
        start=NULL;
        end=NULL;
    }
    void node_front();
    void check();
    void node_last();
    void node_bet(int);
    void update(int);
    void display();
    void deletion(int);
    void report();
    void getback();
};
Node *backup=new Node;
void input(Node *news){
    backup=NULL;
    cout<<"Enter employee number\n";
    cin>>news->e.no;
    cout<<"Enter name\n";
    cin>>news->e.name;
    cout<<"Enter father's name\n";
    cin>>news->e.father;
    cout<<"Enter department\n";
    cin>>news->e.depart;
    cout<<"Enter year of joining\n";
    cin>>news->e.joining;
    cout<<"Enter year of retirement\n";
    cin>>news->e.retire;
    cout<<"Enter year of house number\n";
    cin>>news->e.a.house;
    cout<<"ENter village/town\n";
    cin>>news->e.a.village;
    cout<<"Enter year of city\n";
    cin>>news->e.a.city;
    cout<<"Enter year of pincode\n";
    cin>>news->e.a.pin;
    cout<<"Enter year of state\n";
    cin>>news->e.a.state;
}
void linkedlist::check(){
    linkedlist list;
     int place;
        cout<<"Enter 1 - add data at front\n";
        cout<<"Enter 2 - add data at last\n";
        cout<<"Enter 3 - add data at desired position\n";
        int a;
        cin>>a;
        switch(a){
            case 1:
            list.node_front();
            break;
            case 2:
            list.node_last();
            break;
            case 3:
            cout<<"Enter position\n";
            cin>>place;
            list.node_bet(place);
            break;
            default:
            cout<<"No match\n";
            break;
        }
}
void linkedlist::node_front(){
    Node *news=new Node;
    news->next=NULL;
    input(news);
    if(start==NULL){
        start=news;
        end=news;
    }
    else{
        news->next=start;
        start=news;
    }
}
void linkedlist::node_last(){
    Node *news=new Node;
    news->next=NULL;
    input(news);
    if(start==NULL){
        start=news;
        end=start;
        return;
    }
    else{
        end->next=news;
        end=end->next;
        return;
    }
}
void linkedlist::node_bet(int pos){
    Node *prev=new Node;
    Node *current=new Node;
    current=start;
    Node *news=new Node;
    news->next=NULL;
    input(news);
    if(pos<1){
        cout<<"Position cannot be negative\n";
    }
    else if(pos==1){
        news->next=start;
        start=news;
    }
    else{
        for(int i=1;i<pos;i++){
            prev=current;
            current=current->next;
            if(current==NULL){
                cout<<"Invalid position\n";
                return;
            }
        }
        prev->next=news;
        news->next=current;
    }
}
void linkedlist::update(int value){
    Node *current=start;
    while(current!=NULL){
        if(current->e.no==value){
            input(current);
            return;
        }
        current=current->next;
    }
    cout<<"Element not found\n";
}
void linkedlist::display(){
    Node *current=start;
    cout<<setw(5)<<"Name"<<setw(5)<<"Name"<<setw(10)<<"Fathers Name"<<setw(10)<<"Year of joining"<<setw(10)<<"Department"<<setw(10)<<"Year of retirement"<<setw(5)<<"House no."<<setw(5)<<"Village/town"<<setw(5)<<"City"<<setw(5)<<"Pincode"<<setw(5)<<"State"<<endl;
    while(current!=NULL){
        cout<<setw(5)<<current->e.no<<setw(5)<<current->e.name<<setw(5)<<current->e.father<<setw(5)<<current->e.joining<<setw(5)<<current->e.depart<<setw(5)<<current->e.retire<<setw(5)<<current->e.a.house<<setw(5)<<current->e.a.village<<setw(5)<<current->e.a.city<<setw(5)<<current->e.a.pin<<setw(5)<<current->e.a.state<<endl;
        current=current->next;
    }
}
void linkedlist::deletion(int a){
    bool flag=false;
    Node *current=new Node;
    Node *prev=new Node;
    prev=start;
    current=start;
    while(current!=NULL){
        if(current->e.no==a && current==start){
            start=current->next;
            if(backup==NULL){
            backup=current;
            backup->next=NULL;
            }
            else{
                backup->next=current;
            }
            free(current);
            flag=true;
            break;
        }
        else if(current->e.no==a){
            prev->next=current->next;
            if(current==end){
                end=prev;
            if(backup==NULL){
                backup=current;
                backup->next=NULL;
            }
            else{
                backup->next=current;
            }}
            free(current);
            flag=true;
            break;
        }
        else{
            prev=current;
            current=current->next;
        }
    }
    if(flag==true){
        cout<<"Required data deleted\n";
    }
    else{
        cout<<"Required data not found\n";
    }
}
void linkedlist::report(){
    int c=0;
    Node *current=start;
    Node *find=NULL;
    cout<<"Enter 1 - report for employee belonging to  same state\n";
    cout<<"Enter 2 - report for employee retiring at same year\n";
    cout<<"Enter 3 - report for employee joining at same year\n";
    int d;
    cin>>d;
    if(d==1){
    while(current!=NULL){
        find=current->next;
        if(current->e.a.state==find->e.a.state){
            cout<<setw(5)<<current->e.no<<setw(5)<<current->e.name<<setw(5)<<current->e.father<<setw(5)<<current->e.joining<<setw(5)<<current->e.depart<<setw(5)<<current->e.retire<<setw(5)<<current->e.a.house<<setw(5)<<current->e.a.village<<setw(5)<<current->e.a.city<<setw(5)<<current->e.a.pin<<setw(5)<<current->e.a.state<<endl;
            cout<<setw(5)<<find->e.no<<setw(5)<<find->e.name<<setw(5)<<find->e.father<<setw(5)<<find->e.joining<<setw(5)<<find->e.depart<<setw(5)<<find->e.retire<<setw(5)<<find->e.a.house<<setw(5)<<find->e.a.village<<setw(5)<<find->e.a.city<<setw(5)<<find->e.a.pin<<setw(5)<<find->e.a.state<<endl;
        }
        current=current->next;
    }
    }
    else if(d==2){
        while(current!=NULL){
        find=current->next;
        if(current->e.retire==find->e.retire){
            cout<<setw(5)<<current->e.no<<setw(5)<<current->e.name<<setw(5)<<current->e.father<<setw(5)<<current->e.joining<<setw(5)<<current->e.depart<<setw(5)<<current->e.retire<<setw(5)<<current->e.a.house<<setw(5)<<current->e.a.village<<setw(5)<<current->e.a.city<<setw(5)<<current->e.a.pin<<setw(5)<<current->e.a.state<<endl;
            cout<<setw(5)<<find->e.no<<setw(5)<<find->e.name<<setw(5)<<find->e.father<<setw(5)<<find->e.joining<<setw(5)<<find->e.depart<<setw(5)<<find->e.retire<<setw(5)<<find->e.a.house<<setw(5)<<find->e.a.village<<setw(5)<<find->e.a.city<<setw(5)<<find->e.a.pin<<setw(5)<<find->e.a.state<<endl;
        }
        current=current->next;
        }
    }
    else if(d==3){
        while(current!=NULL){
        find=current->next;
        if(current->e.joining==find->e.joining){
            cout<<setw(5)<<current->e.no<<setw(5)<<current->e.name<<setw(5)<<current->e.father<<setw(5)<<current->e.joining<<setw(5)<<current->e.depart<<setw(5)<<current->e.retire<<setw(5)<<current->e.a.house<<setw(5)<<current->e.a.village<<setw(5)<<current->e.a.city<<setw(5)<<current->e.a.pin<<setw(5)<<current->e.a.state<<endl;
            cout<<setw(5)<<find->e.no<<setw(5)<<find->e.name<<setw(5)<<find->e.father<<setw(5)<<find->e.joining<<setw(5)<<find->e.depart<<setw(5)<<find->e.retire<<setw(5)<<find->e.a.house<<setw(5)<<find->e.a.village<<setw(5)<<find->e.a.city<<setw(5)<<find->e.a.pin<<setw(5)<<find->e.a.state<<endl;
        }
        current=current->next;
        }
    }
}
void linkedlist::getback(){
    cout<<"The backup of data is successfull\n";
    if(end==NULL){
        end=backup;
    }
    else{
        end->next=backup;
    }
}
class data{
    public:
    linkedlist l;
    void input();
    void update();
    void deletion();
    void backups();
};
int main(){
    linkedlist l;
    int s,e;
    while(1){
        cout<<"Enter 1 - input the data\n";
        cout<<"Enter 2 - update the data\n";
        cout<<"Enter 3 - delete the data\n";
        cout<<"Enter 4 - display data\n";
        cout<<"Enter 5 - display report\n";
        cout<<"Enter 6 - exit the data\n";
        cin>>s;
        switch(s){
            case 1:
            l.check();
            break;
            case 2:
            cout<<"Enter number of employee to be updated\n";
            cin>>e;
            l.update(e);
            break;
            case 3:
            cout<<"Enter number of employee to be updated\n";
            cin>>e;
            l.deletion(e);
            break;
            case 4:
            l.display();
            break;
            case 5:
            l.report();
            break;
            case 6:
            l.display();
            exit(0);
            break;
            default:
            cout<<"No match\n";
            break;
        }
    }
}