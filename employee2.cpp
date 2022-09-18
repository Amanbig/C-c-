#include<iostream>
#include<iomanip>
using namespace std;
class address{
    public:
    int house, pin;
    string village, city, state;
};
class employee{
    public:
    int no, joining, retire;
    string name, father, depart;
    address a;
};
struct node{
    employee e;
    node *next;
};
node* start = NULL;
node *backup=NULL;
class data{
    public:
    void input(node *);
    void insert();
    void display(node *);
    void sort();
    void backups();
    void update();
    void deletion();
    void report();
};
void data::input(node *news){
    system("CLS");
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
    if(news->e.retire<news->e.joining){
        cout<<"Please reenter retirement year\n";
        cin>>news->e.retire;
    }
    cout<<"Enter house number\n";
    cin>>news->e.a.house;
    cout<<"Enter village/town\n";
    cin>>news->e.a.village;
    cout<<"Enter city\n";
    cin>>news->e.a.city;
    cout<<"Enter pincode\n";
    cin>>news->e.a.pin;
    cout<<"Enter state\n";
    cin>>news->e.a.state;
}
void data::insert(){
    node* new_node = new node;
    input(new_node);
    new_node->next   = NULL;
    if (start == NULL) {
        start = new_node;
    }
    else {
        node * temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}
void data::update(){
    system("CLS");
    node* current=start;
    int num;
    cout<<"Enter employee number to be updated\n";
    cin>>num;
    for (current=start;current!=NULL;current=current->next){
        if (current->e.no==num){
            cout<<"Enter name\n";
            cin>>current->e.name;
            cout<<"Enter father's name\n";
            cin>>current->e.father;
            cout<<"Enter department\n";
            cin>>current->e.depart;
            cout<<"Enter year of joining\n";
            cin>>current->e.joining;
            cout<<"Enter year of retirement\n";
            cin>>current->e.retire;
            if(current->e.retire<current->e.joining){
                cout<<"Please reenter retirement year\n";
                cin>>current->e.retire;
            }
            cout<<"Enter house number\n";
            cin>>current->e.a.house;
            cout<<"Enter village/town\n";
            cin>>current->e.a.village;
            cout<<"Enter city\n";
            cin>>current->e.a.city;
            cout<<"Enter pincode\n";
            cin>>current->e.a.pin;
            cout<<"Enter state\n";
            cin>>current->e.a.state;
        }
    }
}
void data::deletion(){
    system("CLS");
    node* current=start;
    int num;
    cout<<"Enter employee number to be deleted\n";
    cin>>num;
    node* temp=NULL;
    char d;
    for (current=start;current!=NULL;current=current->next){
        if (current->e.no==num) {
            cout<<"Are you sure you want to delete[y/n]: ";
            cin>>d;
            if (d=='y' || d=='Y') {
                if (current==start){
                    start=current->next;
                    if(backup==NULL){
                        backup=current;
                    }
                    else{
                        node * temps = backup;
                        while (temps->next != NULL)
                            temps = temp->next;
                        temps->next = current;
                    }
                }
                else{
                    temp->next=current->next;
                    if(backup==NULL){
                        backup=current;
                    }
                    else{
                        node * temps = backup;
                        while (temps->next != NULL)
                            temps = temp->next;
                        temps->next = current;
                    }
                }
            }
        }
        else if(current->e.no!=num){
            cout<<"No record found\n";
        }
        temp=current;
    }
}
void data::display(node *current){
        cout<<setw(15)<<current->e.no<<setw(15)<<current->e.name<<setw(15)<<current->e.father<<setw(10)<<current->e.joining<<setw(10)<<current->e.depart<<setw(10)<<current->e.retire<<setw(10)<<current->e.a.house<<setw(10)<<current->e.a.village<<setw(10)<<current->e.a.city<<setw(10)<<current->e.a.pin<<setw(10)<<current->e.a.state<<endl;
}
void data::sort(){
    system("CLS");
    node* current_minimum=NULL;
    node* current_node=NULL;
    int ar;
    for (current_minimum = start; current_minimum != NULL; current_minimum = current_minimum->next) {
        for (current_node = current_minimum->next; current_node != NULL;  current_node = current_node->next) {
            if (current_node->e.no<current_minimum->e.no) {
                ar  = current_minimum->e.no;
                current_minimum->e.no   = current_node->e.no;
                current_node->e.no   = ar;
            }
        }
    }
    cout<<setw(15)<<"Employee No"<<setw(15)<<"Name"<<setw(15)<<"Fathers Name"<<setw(10)<<"Year of joining"<<setw(10)<<"Department"<<setw(10)<<"Year of retirement"<<setw(10)<<"House no."<<setw(10)<<"Village/town"<<setw(10)<<"City"<<setw(10)<<"Pincode"<<setw(10)<<"State"<<endl;
    for(current_minimum=start;current_minimum!=NULL;current_minimum=current_minimum->next){
        display(current_minimum);
    }
}
void data::backups(){
    if(backup==NULL){
        cout<<"No backup found\n";
    }
    else{
    if (start == NULL) {
        start = backup;
    }
    else {
        node * temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = backup;
    }}
    cout<<"Backup is successful\n";
}
void data::report(){
    system("CLS");
    node *current=start;
    node *find=NULL;
    cout<<"Enter 1 - report for employee belonging to  same state\n";
    cout<<"Enter 2 - report for employee retiring at same year\n";
    cout<<"Enter 3 - report for employee joining at same year\n";
    int d;
    cin>>d;
    if(d==1){
    for (current = start; current != NULL; current = current->next) {
        for (find = current->next; find != NULL;  find = find->next) {
            if (current->e.a.state==find->e.a.state) {
                cout<<setw(5)<<current->e.no<<setw(5)<<current->e.name<<setw(5)<<current->e.father<<setw(5)<<current->e.joining<<setw(5)<<current->e.depart<<setw(5)<<current->e.retire<<setw(5)<<current->e.a.house<<setw(5)<<current->e.a.village<<setw(5)<<current->e.a.city<<setw(5)<<current->e.a.pin<<setw(5)<<current->e.a.state<<endl;
                cout<<setw(5)<<find->e.no<<setw(5)<<find->e.name<<setw(5)<<find->e.father<<setw(5)<<find->e.joining<<setw(5)<<find->e.depart<<setw(5)<<find->e.retire<<setw(5)<<find->e.a.house<<setw(5)<<find->e.a.village<<setw(5)<<find->e.a.city<<setw(5)<<find->e.a.pin<<setw(5)<<find->e.a.state<<endl;
            }
        }
    }
    }
    else if(d==2){
        for (current = start; current != NULL; current = current->next) {
        for (find = current->next; find != NULL;  find = find->next) {
            if (current->e.retire==find->e.retire) {
                cout<<setw(5)<<current->e.no<<setw(5)<<current->e.name<<setw(5)<<current->e.father<<setw(5)<<current->e.joining<<setw(5)<<current->e.depart<<setw(5)<<current->e.retire<<setw(5)<<current->e.a.house<<setw(5)<<current->e.a.village<<setw(5)<<current->e.a.city<<setw(5)<<current->e.a.pin<<setw(5)<<current->e.a.state<<endl;
                cout<<setw(5)<<find->e.no<<setw(5)<<find->e.name<<setw(5)<<find->e.father<<setw(5)<<find->e.joining<<setw(5)<<find->e.depart<<setw(5)<<find->e.retire<<setw(5)<<find->e.a.house<<setw(5)<<find->e.a.village<<setw(5)<<find->e.a.city<<setw(5)<<find->e.a.pin<<setw(5)<<find->e.a.state<<endl;
            }
        }
    }
    }
    else if(d==3){
        for (current = start; current != NULL; current = current->next) {
        for (find = current->next; find != NULL;  find = find->next) {
            if (current->e.joining==find->e.joining) {
                cout<<setw(5)<<current->e.no<<setw(5)<<current->e.name<<setw(5)<<current->e.father<<setw(5)<<current->e.joining<<setw(5)<<current->e.depart<<setw(5)<<current->e.retire<<setw(5)<<current->e.a.house<<setw(5)<<current->e.a.village<<setw(5)<<current->e.a.city<<setw(5)<<current->e.a.pin<<setw(5)<<current->e.a.state<<endl;
                cout<<setw(5)<<find->e.no<<setw(5)<<find->e.name<<setw(5)<<find->e.father<<setw(5)<<find->e.joining<<setw(5)<<find->e.depart<<setw(5)<<find->e.retire<<setw(5)<<find->e.a.house<<setw(5)<<find->e.a.village<<setw(5)<<find->e.a.city<<setw(5)<<find->e.a.pin<<setw(5)<<find->e.a.state<<endl;
            }
        }
    }}
    else{
        cout<<"No match to your selection\n";
    }
}
int main(){
    system("CLS");
    data d;
    while(1){
        cout<<"Enter 1 - add a record\n";
        cout<<"Enter 2 - update a record\n";
        cout<<"Enter 3 - delete a record\n";
        cout<<"Enter 4 - create report on enterned data\n";
        cout<<"Enter 5 - backup record\n";
        cout<<"Enter 6 - display record\n";
        cout<<"Enter 7 - exit\n";
        int choice;
        cin>>choice;
        switch (choice){
            case 1:
            d.insert();
            break;
            case 2:
            d.update();
            break;
            case 3:
            d.deletion();
            break;
            case 4:
            d.report();
            break;
            case 5:
            d.backups();
            break;
            case 6:
            d.sort();
            break;
            case 7:
            exit(0);
            break;
            default:
            cout<<"No match to your selection\n";
            break;
        }
    }
}