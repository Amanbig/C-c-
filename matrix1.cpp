#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"Enter number\n";
    cin>>a;
    int *a1=new int(a*a);
    int *a2=new int(a*a+*a1);
    int *a3=new int(a*a+*a2);
    cout<<"Enter matrix\n";
    for(b=1;b<=a*a;b++){
        cin>>(*(a1+b));
    }
    cout<<"Enter second matrix\n";
    for(b=1;b<=a*a;b++){
        cin>>(*(a2+b));
    }
    cout<<"Sum of matrix is\n";
    for(b=1;b<=a*a;b++){
        *(a3+b)=*(a1+b)+*(a2+b);
    }
    for(b=1;b<=a*a;b++){
        cout<<(*(a3+b))<<"\t";
        if(b%a==0)
        cout<<"\n";
    }
}