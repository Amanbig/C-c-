#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class vertex{
    public:
    int id=0;
    vertex *p=NULL;
    int d=9999999;
};
int ar[100][100];
vector<vertex*> v;
int ver=0;
void dijkstra(int a){
    vertex* c;
    for(int i=0;i<ver;i++){
        c=new vertex();
        c->id=i;
        v.push_back(c);
    }
    v[0]->d=0;
    queue<vertex*> q;
    q.push(v[0]);
    while(!q.empty()){
        vertex* u=q.front();
        q.pop();
        for(int i=0;i<ver;i++){
            if(ar[u->id][i]!=0){
                if(v[i]->d>u->d+ar[u->id][i]){
                    v[i]->d=u->d+ar[u->id][i];
                    v[i]->p=u;
                    q.push(v[i]);
                }
            }
        }
    }
}
int main(){
    int a,b;
    cout<<"Enter number of vertices\n";
    cin>>a;
    ver=a;
    int choice=-1;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            ar[i][j]=0;
        }
    }
    while(choice!=0){
        int c,d;
        cout<<"Enter 1 - input edge\n";
        cout<<"Enter 0 - execute bfs\n";
        cin>>choice;
        if(choice==1){
            cout<<"Enter initial vertex\n";
            cin>>c;
            while(c>=ver){
                cout<<"Enter initial vertex again\n";
                cin>>c;
            }
            cout<<"Enter final vertex\n";
            cin>>d;
            while(d>=ver){
                cout<<"Enter final vertex again\n";
                cin>>d;
            }
            cout << "Enter edge weight: ";
            int weight;
            cin >> weight;
            ar[c][d] = weight;
        }
        else if(choice==0){
            break;
        }
        else{
            cout<<"Not valid choice\n";
        }
    }
    cout<<"Enter initial vertex\n";
    cin>>b;
    dijkstra(b);
    cout<<"The distances are as follows\n";
    for(int i=0;i<ver;i++){
        cout<<v[i]->id<<" "<<v[i]->d<<endl;
    }
    return 0;
}