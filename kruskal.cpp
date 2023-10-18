#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
int ar[100][100];
int ver=0;
vector<vector<int>> v;
class disjoint{
    public:
    void make_set(int a){
        vector<int> b;
        parent.push_back(a);
        b.push_back(a);
        v.push_back(b);
    }
    int find_set(int a){
        return parent[a];   
    }
    void union_set(int a,int b){
        parent[b]=parent[a];
        vector<int> mergedVector = v[a]; 
        mergedVector.insert(mergedVector.end(), v[b].begin(), v[b].end());
        v[a] = mergedVector;
        vector<vector<int>> c;
        for(int i=0;i<v.size();i++){
            if(i==b){
                continue;
            }
            else{
                c.push_back(v[i]);
            }
        }
        v=c;
    }
};
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void sorting(vector<int> t,vector<pair<int,int>> e){
    for(int i=0;i<t.size();i++){
        for(int j=i+1;j<t.size();j++){
            if(t[i]>t[j]){
                swap(t[i],t[j]);
                swap(e[i].first,e[j].first);
                swap(e[i].second,e[j].second);
            }
        }
    }
}
void kruskals(){
    disjoint d;
    for(int i=0;i<ver;i++){
        d.make_set(i);
    }
    vector<int> t;
    vector<pair<int,int>> e;
    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            if(ar[i][j]!=0){
                t.push_back(ar[i][j]);
                e.push_back(make_pair(i,j));
            }
        }
    }
    sorting(t,e);
    vector<pair<int,int>> b;
    for(int i=0;i<ver;i++){
        if(d.find_set(e[i].first)!=d.find_set(e[i].second)){
            b.push_back(make_pair(e[i].first,e[i].second));
            d.union_set(e[i].first,e[i].second);
        }
    }
    for(int i=0;i<b.size();i++){
        cout<<b[i].first<<"-"<<b[i].second<<endl;
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
        cout<<"Enter 0 - execute primes\n";
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
    kruskals();
    return 0;
}