#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class dates{
    public:
    int day;
    int month;
    int year;
};
class parts{
    public:
    string comp_id;
    string parts_id;
    string names;
    dates manu;
    dates expiry;
};
class machine{
    parts part;
    int count=0;
    machine *next;
    machine *prev;
    public:
    machine *head=NULL;
    machine *tail=NULL;
    machine(){
        next=NULL;
        prev=NULL;
    }
    void insert();
    void deletion();
    void display();
    void input(machine *);
    void counts();
    void expired();
    void queries();
    void backup();
};
void machine::insert(){
    machine *news=new machine;
    input(news);
    count++;
    if(head==NULL){
        head=news;
        tail=news;
    }
    else if(head->next==NULL){
        head->next=news;
        news->prev=head;
        tail=news;
    }
    else{
        int a;
        cout<<"Enter position to insert\n";
        cin>>a;
        if(a<0){
            cout<<"Position cannot be negative\n";
        }
        else{
            if(a==0){
                news->next=head;
                head->prev=news;
                head=news;
            }
            else if(a==1){
                news->next=head->next;
                news->prev=head;
                head->next=news;
            }
            else{
                machine *temp=head;
                int b=0;
                bool c=true;
                while(temp!=NULL){
                    b++;
                    if(b==a-1){
                        c=true;
                        break;
                    }
                    else{
                        c=false;
                    }
                    temp=temp->next;
                }
                if(c){
                    news->next=temp->next;
                    news->prev=temp;
                    temp->next->prev=news;
                    temp->next=news;
                }
                else{
                    if(b==a){
                        news->next=NULL;
                        news->prev=tail;
                        tail->next=news;
                        tail=news;
                    }
                    else{
                        cout<<"Location not found\n";
                    }
                }
            }
        }
    }
}
void machine::deletion(){
    if(head==NULL){
        cout<<"No data found\n";
    }
    else if(head->next==NULL){
        machine *temp=head;
        head=tail=NULL;
        delete temp;
    }
    else{
        string a,b;
        cout<<"Enter company id\n";
        cin>>a;
        cout<<"Enter parts id\n";
        cin>>b;
            bool c=true;
            machine *temp=head;
            while(temp!=NULL){
                if(temp->part.comp_id==a&&temp->part.parts_id==b){
                    c=true;
                    break;
                }
                else{
                    c=false;
                }
                temp=temp->next;
            }
            if(c){
                if(temp==tail){
                    machine *temps=temp;
                    temp->next=NULL;
                    temp->prev->next=NULL;
                    tail=temp->prev;
                    temp->prev=NULL;
                    delete temps;
                }
                else{
                    machine *temps=temp;
                    temp->prev->next=temp->next->next;
                    temp->next->prev=temp->prev;
                    delete temps;
                }
            }
            else{
                    cout<<"Unable to find record\n";
            }
        }
}
void machine::display(){
    machine *temp=head;
    cout<<setw(10)<<"Company ID"<<setw(10)<<"Parts ID"<<setw(10)<<"Parts Name"<<setw(10)<<"Date of Manufacture"<<setw(10)<<"Date of expiry\n";
    while(temp!=NULL){
        cout<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        temp=temp->next;
    }
}
void machine::input(machine *news){
    cout<<"Enter company id\n";
    cin>>news->part.comp_id;
    cout<<"Enter parts id\n";
    cin>>news->part.parts_id;
    cout<<"Enter Parts name\n";
    cin>>news->part.names;
    cout<<"Enter date of manufacture\n";
    cin>>news->part.manu.day>>news->part.manu.month>>news->part.manu.year;
    if((news->part.manu.day>31 && news->part.manu.day<0)||(news->part.manu.month>12 && news->part.manu.month<0)||(news->part.manu.year<0)){
        cout<<"please reenter date of manufacture\n";
        cin>>news->part.manu.day>>news->part.manu.month>>news->part.manu.year;
    }
    cout<<"Enter date of expiry\n";
    cin>>news->part.expiry.day>>news->part.expiry.month>>news->part.expiry.year;
    if((news->part.expiry.day>31 && news->part.expiry.day<0)||(news->part.expiry.month>12 && news->part.expiry.month<0)||(news->part.expiry.year<0)){
        cout<<"please reenter date of expiry\n";
        cin>>news->part.expiry.day>>news->part.expiry.month>>news->part.expiry.year;
    }
    else if(news->part.expiry.day==news->part.manu.day&&news->part.expiry.month==news->part.manu.month&&news->part.expiry.year==news->part.manu.year){
        cout<<"The date of expiry cannot be equal to date of manufacture\n";
        cin>>news->part.expiry.day>>news->part.expiry.month>>news->part.expiry.year;
    }
}
void machine::counts(){
    cout<<"Total number of parts:"<<count<<endl;
}
void machine::expired(){
    machine *temp=head;
    cout<<"This is list of expired machine parts\n";
    while(temp!=NULL){
        if(temp->part.expiry.day<19&&temp->part.expiry.month<9&&temp->part.expiry.year<2022){
            cout<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        }
        temp=temp->next;
    }
}
void machine::queries(){
    string query;
    cout<<"Enter query to arrange the list\n";
    cin>>query;
    machine *temp=head;
    if(query=="expiry"){
        cout<<"This is list of expired medicines\n";
        while(temp!=NULL){
        if(temp->part.expiry.day<19&&temp->part.expiry.month<9&&temp->part.expiry.year<2022){
            cout<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        }
        temp=temp->next;
    }
    }
    else if(query=="manufacture" || query=="not_expired"){
        cout<<"This is list of medicines not expired\n";
        while(temp!=NULL){
        if(temp->part.expiry.day>19&&temp->part.expiry.month>9&&temp->part.expiry.year>=2022){
            cout<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        }
        temp=temp->next;
    }
    }
    else if(query=="company"){
        string a;
        cout<<"Enter company id\n";
        cin>>a;
        cout<<"This is list of parts from same company\n";
        while(temp!=NULL){
        if(temp->part.comp_id==a){
            cout<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        }
        temp=temp->next;
    }
    }
    else if (query=="parts"){
        string a;
        cout<<"Enter parts id\n";
        cin>>a;
        cout<<"This is list of parts with same parts id\n";
        while(temp!=NULL){
        if(temp->part.parts_id==a){
            cout<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        }
        temp=temp->next;
    }
    }
    else if(query=="name"){
        string a;
        cout<<"Enter name\n";
        cin>>a;
        cout<<"This is list of parts with same name\n";
        while(temp!=NULL){
        if(temp->part.names==a){
            cout<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        }
        temp=temp->next;
    }
    }
}
void machine::backup(){
    ofstream outf("machine.txt");
    machine *temp=head;
    while(temp!=NULL){
        outf<<setw(10)<<temp->part.comp_id<<setw(10)<<temp->part.parts_id<<setw(10)<<temp->part.names<<setw(10)<<temp->part.manu.day<<"/"<<temp->part.manu.month<<"/"<<temp->part.manu.year<<setw(10)<<temp->part.expiry.day<<"/"<<temp->part.expiry.month<<"/"<<temp->part.expiry.year<<endl;
        temp=temp->next;
    }
    outf.close();
}
int main(){
    int a;
    char c;
    machine m;
    while(1){
        cout<<"Enter 1 - addition of record\n";
        cout<<"Enter 2 - deletion of record\n";
        cout<<"Enter 3 - displaying record\n";
        cout<<"Enter 4 - backup record\n";
        cout<<"Enter 5 - find number of record\n";
        cout<<"Enter 6 - list of expired machine\n";
        cout<<"Enter 7 - quries\n";
        cout<<"Enter 8 - exit\n";
        cin>>a;
        switch(a){
            case 1:
            system("CLS");
            m.insert();
            break;
            case 2:
            system("CLS");
            m.deletion();
            break;
            case 3:
            system("CLS");
            m.display();
            break;
            case 4:
            m.backup();
            break;
            case 5:
            system("CLS");
            m.counts();
            break;
            case 6:
            system("CLS");
            m.expired();
            break;
            case 7:
            system("CLS");
            m.queries();
            case 8:
            system("CLS");
            m.display();
            exit(0);
            default:
            cout<<"No match to your selection\n";
            break;
        }
    }
}