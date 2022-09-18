#include<iostream>
using namespace std;
class sum{
    int a;
    public:
    void input(){
        cout<<"Enter number\n";
        cin>>a;
    }
    int fac(int a){
        if(a==1||a==0)
        return 1;
        else{
            return a*fac(a-1);
        }
    }
    void display(){
        cout<<fac(a)<<endl;
    }
};
int main(){
    int a,b;
    cout<<"Enter number\n";
    cin>>a;
    sum s[a];
    for(b=0;b<a;b++){
        s[b].input();
    }
    for(b=0;b<a;b++){
        s[b].display();
    }
}