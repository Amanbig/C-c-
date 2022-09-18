#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cout<<"Enter number\n";
    cin>>a;
    int ar[a][a],br[a][a],cr[a][a];
    cout<<"Enter first matrix\n";
    for(b=0;b<a;b++){
        for(c=0;c<a;c++){
            cin>>ar[b][c];
        }
    }
    cout<<"Enter second matrix\n";
    for(b=0;b<a;b++){
        for(c=0;c<a;c++){
            cin>>br[b][c];
        }
    }
    cout<<"The multiplication of matrix is\n";
    for(b=0;b<a;b++){
        for(c=0;c<a;c++){
            cr[b][c]=0;
            for(d=0;d<a;d++){
                cr[b][c]+=ar[b][d]*br[d][c];
            }
        }
    }
    for(b=0;b<a;b++){
        for(c=0;c<a;c++){
            cout<<cr[b][c]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}