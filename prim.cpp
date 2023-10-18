#include<iostream>
#include<vector>
using namespace std;
int ar[100][100];
class vertex{
    public:
    int id;
    int key=9999999;
    vertex* p=NULL;
};
vector<vertex*> v;
int ver=0;
class node{
    public:
    vertex* data;
    node* next;
    node(vertex* data){
        this->data = data;
        next = NULL;
    }
};
class priority{
    public:
    node * head = NULL;
    void push(vertex* a){
        node *news = new node(a);
        if(empty()){
            head=news;
        }
        else if(head->data->key>=a->key&&head->next==NULL){
            news->next=head;
            head=news;
        }
        else if(head->data->key<a->key&&head->next==NULL){
            head->next=news;
        }
        else{
            node * temp=head;
            while(temp->next!=NULL&&temp->next->data<news->data){
                temp=temp->next;
            }
            news->next=temp->next;
            temp->next=news;
        }
    }
    vertex* pop(){
        node *temp=head;
        vertex* a=temp->data;
        head=head->next;
        delete temp;
        return a;
    }
    bool empty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool find(vertex* a){
        node* temp=head;
        while(temp!=NULL){
            if(temp->data->id==a->id){
                return true;
            }
        }
        return false;
    }
};
void primes(int a){
    vertex *c;
    for(int i=0;i<ver;i++){
        c=new vertex();
        c->id=i;
        v.push_back(c);
    }
    v[a]->key=0;
    priority p;
    for(int i=0;i<ver;i++){
        p.push(v[i]);
    }
    while(!p.empty()){
        vertex *u=p.pop();
        for(int i=0;i<ver;i++){
            if(ar[u->id][i]!=0){
                if(p.find(v[i])&&ar[u->id][i]<v[i]->key){
                    v[i]->key=ar[u->id][i];
                    v[i]->p=u;
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
    cout<<"Enter initial vertex\n";
    cin>>b;
    primes(b);
    cout<<"The distances are as follows\n";
    for(int i=0;i<ver;i++){
        cout<<v[i]->id<<" "<<v[i]->key<<endl;
    }
    return 0;
}
