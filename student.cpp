#include<iostream>
#include<iomanip>
using namespace std;
int total=0;
struct date{
    int day, month, year;
}d;
struct data{
    string roll_no, name, father_name, branch, state, country;
    int admission, passing, pin;
    struct date d;
}a1[100];
class student{
    public:
    void input();
    void display();
    void update();
    void deletion();
    void report();
};
void student::input(){
    system("CLS");
    int ch=0;
    cout<<"Enter size of record to be added\n";
    cin>>ch;
    if(total==0){
        total+=ch;
        for(int i=0;i<total;i++){
            cout<<"Enter roll_no\n";
            cin>>a1[i].roll_no;
            cout<<"Enter name\n";
            cin>>a1[i].name;
            cout<<"Enter dob\n";
            cin>>a1[i].d.day>>a1[i].d.month>>a1[i].d.year;
                if((a1[i].d.day<=0 && a1[i].d.day >=31)||(a1[i].d.month<=0 && a1[i].d.month>=12)){
                    cout<<"Please reenter date\n";
                    cin>>a1[i].d.day>>a1[i].d.month>>a1[i].d.year;
                }
            cout<<"Enter father's name\n";
            cin>>a1[i].father_name;
            cout<<"Enter branch\n";
            cin>>a1[i].branch;
            cout<<"Enter admission year\n";
            cin>>a1[i].admission;
            if(a1[i].admission<=a1[i].d.year){
                cout<<"The year cannot be less than or equal to year of birth\n";
                cout<<"Please reenter\n";
                cin>>a1[i].admission;
            }
            cout<<"Enter year of passing\n";
            cin>>a1[i].passing;
            if(a1[i].passing<=a1[i].d.year && a1[i].passing<=a1[i].admission){
                cout<<"Please reenter year of passing\n";
                cin>>a1[i].passing;
            }
            cout<<"Enter state\n";
            cin>>a1[i].state;
            cout<<"Enter pincode\n";
            cin>>a1[i].pin;
            cout<<"Enter country\n";
            cin>>a1[i].country;
        }
    }
    else{
        for(int i=0;i<total+ch;i++){
            cout<<"Enter roll_no\n";
            cin>>a1[i].roll_no;
            cout<<"Enter name\n";
            cin>>a1[i].name;
            cout<<"Enter dob\n";
            cin>>a1[i].d.day>>a1[i].d.month>>a1[i].d.year;
                if((a1[i].d.day<=0 && a1[i].d.day >=31)||(a1[i].d.month<=0 && a1[i].d.month>=12)){
                    cout<<"Please reenter date\n";
                    cin>>a1[i].d.day>>a1[i].d.month>>a1[i].d.year;
                }
            cout<<"Enter father's name\n";
            cin>>a1[i].father_name;
            cout<<"Enter branch\n";
            cin>>a1[i].branch;
            cout<<"Enter admission year\n";
            cin>>a1[i].admission;
            if(a1[i].admission<=a1[i].d.year){
                cout<<"The year cannot be less than or equal to year of birth\n";
                cout<<"Please reenter\n";
                cin>>a1[i].admission;
            }
            cout<<"Enter year of passing\n";
            cin>>a1[i].passing;
            if(a1[i].passing<=a1[i].d.year && a1[i].passing<=a1[i].admission){
                cout<<"Please reenter year of passing\n";
                cin>>a1[i].passing;
            }
            cout<<"Enter state\n";
            cin>>a1[i].state;
            cout<<"Enter pincode\n";
            cin>>a1[i].pin;
            cout<<"Enter country\n";
            cin>>a1[i].country;
        }
        total=total+ch;
    }
}
void student::display(){
    system("CLS");
    if(total==0){
        cout<<"No data found\n";
    }
    else{
        cout<<setw(10)<<"Roll_no"<<setw(10)<<"Name"<<setw(20)<<"Father's name"<<setw(20)<<"Date of birth"<<setw(10)<<"Branch"<<setw(20)<<"Year of admission"<<setw(20)<<"year of passing"<<setw(15)<<"state"<<setw(15)<<"PIN"<<setw(15)<<"Country"<<"\n";
        for(int i=0;i<total;i++){
            cout<<setw(10)<<a1[i].roll_no<<setw(10)<<a1[i].name<<setw(20)<<a1[i].father_name<<setw(10)<<a1[i].d.day<<"/"<<a1[i].d.month<<"/"<<a1[i].d.year<<setw(10)<<a1[i].branch<<setw(20)<<a1[i].admission<<setw(20)<<a1[i].passing<<setw(15)<<a1[i].state<<setw(15)<<a1[i].pin<<setw(15)<<a1[i].country<<"\n";
        }
    }
}
void student::update(){
    system("CLS");
    if(total==0){
        cout<<"No data found\n";
    }
    else{
        string roll;
        cout<<"Enter roll no to be updated\n";
        cin>>roll;
        for(int i=0;i<total;i++){
            if(a1[i].roll_no==roll){
                cout<<"Enter name\n";
                cin>>a1[i].name;
                cout<<"Enter dob\n";
                cin>>a1[i].d.day>>a1[i].d.month>>a1[i].d.year;
                if((a1[i].d.day<=0 && a1[i].d.day >=31)||(a1[i].d.month<=0 && a1[i].d.month>=12)){
                    cout<<"Please reenter date\n";
                    cin>>a1[i].d.day>>a1[i].d.month>>a1[i].d.year;
                }
                cout<<"Enter father's name\n";
                cin>>a1[i].father_name;
                cout<<"Enter branch\n";
                cin>>a1[i].branch;
                cout<<"Enter admission year\n";
                cin>>a1[i].admission;
                if(a1[i].admission<=a1[i].d.year){
                    cout<<"The year cannot be less than or equal to year of birth\n";
                    cout<<"Please reenter\n";
                    cin>>a1[i].admission;
                }
                cout<<"Enter year of passing\n";
                cin>>a1[i].passing;
                if(a1[i].passing<=a1[i].d.year && a1[i].passing<=a1[i].admission){
                    cout<<"Please reenter year of passing\n";
                    cin>>a1[i].passing;
                }
                cout<<"Enter state\n";
                cin>>a1[i].state;
                cout<<"Enter pincode\n";
                cin>>a1[i].pin;
                cout<<"Enter country\n";
                cin>>a1[i].country;
            }
        }
    }
}
void student::deletion(){
    system("CLS");
    if(total==0){
        cout<<"No data found\n";
    }
    else{
        cout<<"Press 1 to delete all record"<<endl;
        cout<<"Press 2 to delete specific record"<<endl;
        int a;
        cin>>a;
        if(a==1){
            total=0;
            cout<<"All data deleted\n";
        }
        else if(a==2){
            cout<<"Enter roll no whose data is to deleted\n";
            string roll;
            cin>>roll;
            for(int i=0;i<total;i++){
                a1[i].name=a1[i+1].name;
                a1[i].roll_no=a1[i+1].roll_no;
                a1[i].father_name=a1[i+1].father_name;
                a1[i].branch=a1[i+1].branch;
                a1[i].admission=a1[i+1].admission;
                a1[i].d.day=a1[i+1].d.day;
                a1[i].d.month=a1[i+1].d.month;
                a1[i].d.year=a1[i+1].d.year;
                a1[i].passing=a1[i+1].passing;
                a1[i].state=a1[i+1].state;
                a1[i].pin=a1[i+1].pin;
            }
            total-=1;
            cout<<"Required data is deleted\n";
        }
        else{
            cout<<"Incorrect input\n";
        }
    }
}
void student::report(){
    system("CLS");
    if(total==0){
        cout<<"No record found\n";
    }
    else{
        cout<<"Enter 1 - display report on basis of same name\n";
        cout<<"Enter 2 - display report on basis of same state\n";
        cout<<"Enter 3 - display report on basis of same district\n";
        int a,b=0,c;
        cin>>a;
        if(a==1){
            for(int i=0;i<total;i++){
                for(int j=total-1;i<j;j--){
                    if(a1[i].name==a1[j].name){
                        b++;
                    }
                }
            }
            if(b<=0){
                cout<<"No record with same name found\n";
            }
            else{
                cout<<"The number of record with same name:"<<(b+1)<<endl;
            }
        }
        else if(a==2){
            for(int i=0;i<total;i++){
                for(int j=total-1;i<j;j--){
                    if(a1[i].state==a1[j].state){
                        b++;
                    }
                }
            }
            if(b<=0){
                cout<<"No record with same state found\n";
            }
            else{
                cout<<"The number of record with same state:"<<(b+1)<<endl;
            }
        }
        else if(a==3){
            for(int i=0;i<total;i++){
                for(int j=total-1;i<j;j--){
                    if(a1[i].pin==a1[j].pin){
                        b++;
                    }
                }
            }
            if(b<=0){
                cout<<"No record with same district found\n";
            }
            else{
                cout<<"The number of record with same district:"<<(b+1)<<endl;
            }
        }
    }
}
int main(){
    int a;
    student s;
    while(1){
        cout<<"Enter 1 - input the data\n";
        cout<<"Enter 2 - update the data\n";
        cout<<"Enter 3 - delete the data\n";
        cout<<"Enter 4 - display data\n";
        cout<<"Enter 5 - display report\n";
        cout<<"Enter 6 - exit the data\n";
        cin>>a;
        switch(a){
            case 1:
            s.input();
            break;
            case 2:
            s.update();
            break;
            case 3:
            s.deletion();
            break;
            case 4:
            s.display();
            break;
            case 5:
            s.report();
            break;
            case 6:
            s.display();
            exit(0);
            break;
            default:
            cout<<"No match\n";
            break;
        }
    }
}