#include<iostream>
using namespace std;
int main(){
    int a,b=1,c=1;
    cout<<"Enter number\n";
    cin>>a;
    for(b=1;b<=a;b++){
        c*=b;
    }
    cout<<c<<endl;
    return 0;
}