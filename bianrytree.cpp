#include<iostream>
using namespace std;
class node{
    public:
    string data;
    node *lt,*rt;
    node(string data){
        this->data=data;
        this->lt=NULL;
        this->rt=NULL;
    }
};
class bt{
    public:
    int process(string,int,int);
    void creation();
    void inorder(node *);
    void postorder(node *);
    void preorder(node *);
    int eval(node *);
    int toInt(string);
};
void bt::creation(){
    node* root=new node("-");
    root->lt=new node("20");
    root->rt=new node("+");
    root->rt->lt=new node("5");
    root->rt->rt=new node("*");
    root->rt->rt->lt=new node("/");
    root->rt->rt->rt=new node("3");
    root->rt->rt->lt->lt=new node("6");
    root->rt->rt->lt->rt=new node("2");
    cout<<"Inorder   Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder  Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;
    cout<<"Evaluation of expression is: ";
    cout<<eval(root);
}
void bt::inorder(node *root){
    if(root!=NULL){
        inorder(root->lt);
        cout<<root->data<<" ";
        inorder(root->rt);
    }
}
void bt::postorder(node *root){
    if(root!=NULL){
        postorder(root->lt);
        postorder(root->rt);
        cout<<root->data<<" ";
    }
}
void bt::preorder(node * root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->lt);
        preorder(root->rt);
    }
}
int bt::toInt(string s){
    int temp=0;
    for (int i=0;i<s.length();i++) {
        temp=temp*10+(s[i]-'0');
    }
    return temp;
}
int bt::process(string op,int a,int b){
    if(op=="+"){
        return a+b;
    }
    if(op=="-"){
        return a-b; 
    }
    if(op=="*") {
        return a*b; 
    }
    if(op=="/") {
        return a/b; 
    }
    return 0;
}
int bt::eval(node* root){
    if (root==NULL)
        return 0;
    if (root->lt==NULL && root->rt==NULL)
        return toInt(root->data);
    int a = eval(root->lt);
    int b = eval(root->rt);
    return process(root->data ,a ,b);
}
int main(){
    bt b;
    b.creation();
}