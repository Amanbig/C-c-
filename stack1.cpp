#include<iostream>
using namespace std;
#define size 10
class stk{
    int ar[size];
    int top=-1;
    public:
    void push(){
        if(top==size-1){
            cout<<"Overflow\n";
        }
        else{
            top++;
            cout<<"Enter number\n";
            cin>>ar[top];
        }
    }
    void pop(){
        if(top<=-1){
            cout<<"Underflow\n";
        }
        else{
            top--;
        }
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<ar[i]<<endl;
        }
    }
};
int main(){
    stk s;
    char c;
    int a;
    do{
        cout<<"Enter 1 -push 2- pop 3- display 4-exit\n";
        cin>>a;
        switch(a){
            case 1:
            s.push();
            break;
            case 2:
            s.pop();
            break;
            case 3:
            s.display();
            break;
            case 4:
            s.display();
            c='n';
            break;
            default:
            cout<<"No match\n";
            break;
        }
    }while(c!='n');
}