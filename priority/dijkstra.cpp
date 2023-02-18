#include<iostream>
#include<vector>
#include "prio.h"
using namespace std;
class edge{
    public:
    int ini_id,fin_id;
    int weight;
    edge(){
        ini_id=0;
        fin_id=0;
        weight=0;
    }
    void setid(int,int,int);
    int getini();
    int getfin();
    int getweight();
};
void edge::setid(int a,int c,int b){
    ini_id=a;
    fin_id=b;
    weight=c;
}
int edge::getini(){
    return ini_id;
}
int edge::getfin(){
    return fin_id;
}
int edge::getweight(){
    return weight;
}
class vertex{
    public:
    int id;
    string name;
    void getvertex(int,string);
    int getid();
    string getname();
};
void vertex::getvertex(int a,string b){
    id=a;
    name=b;
}
int vertex::getid(){
    return id;
}
string vertex::getname(){
    return name;
}
class graph{
    vector<edge> e;
    vector<vertex> v;
    public:
    void addvertex(){
        int id;
        string name;
        vertex u;
        cout<<"Enter id of vertex\n";
        cin>>id;
        cout<<"Enter name of vertex\n";
        cin>>name;
        u.getvertex(id,name);
        v.push_back(u);
        cout<<"Vertex added\n";
    }
    void addedge(){
        int ini,fin,w;
        edge ed;
        cout<<"Enter initial vertex\n";
        cin>>ini;
        cout<<"Enter final vertex\n";
        cin>>fin;
        cout<<"Enter weight\n";
        cin>>w;
        ed.setid(ini,w,fin);
        e.push_back(ed);
        cout<<"Edge added\n";
    }
    void print(){
        for(int i=0;i<e.size();i++){
            cout<<e[i].getini()<<"---["<<e[i].getweight()<<"]---"<<e[i].getfin()<<endl;
        }
    }
    void dijkstra(int,int);
};
void graph::dijkstra(int a,int b){
    const int INF = 1000000000;
    vector<int> distance(v.size(),INF);
    distance[a] = 0;
    prio p;
    p.enqueue(0,a);
    while(!p.empty()){
        int u=p.peek();
        p.dequeue();
        for(int i=0;i<e.size();i++){
            if(e[i].getini()==u){
                int v=e[i].getfin();
                int weight=e[i].getweight();
                if(distance[v]>distance[u]+weight){
                    distance[v]=distance[u]+weight;
                    p.enqueue(distance[v],v);
                }
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << "Shortest distance from " << v[a].getname() << " to " << v[i].getname() << " is " << distance[i] << endl;
    }
}
int main(){
    graph g;
    int choice,a,b;
    while(1){
        cout<<"1 - add vertex\n";
        cout<<"2 - add edge\n";
        cout<<"3 - print graph\n";
        cout<<"4 - apply dijkstra\n";
        cout<<"5 - exit\n";
        cin>>choice;
        switch(choice){
            case 1:
            g.addvertex();
            break;
            case 2:
            g.addedge();
            break;
            case 3:
            g.print();
            break;
            case 4:
            cout<<"Enter initial vertex id\n";
            cin>>a;
            cout<<"Enter final vertex id\n";
            cin>>b;
            g.dijkstra(a,b);
            break;
            case 5:
            exit(0);
            break;
            default:
            cout<<"No match to your selection\n";
            break;
        }
    }
}