#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
template <class T>
class stack{
    public:
    T s;
    stack *next;
    stack(){
        next=NULL;
    }
    stack *tops=NULL;
    void push(T c){
        stack *news=new stack;
        news->s=c;
        if (empty()){
            tops=news;
        }
        else{
            news->next=tops;
            tops=news;
        }
    }
    void pop(){
        stack *temp=tops;
        tops=tops->next;
        delete temp;
    }
    T top(){
        return tops->s;
    }
    bool empty(){
        if (tops==NULL){
            return true;
        }
        else
            return false;
    }
};
class pattern{
    public:
    string s;
    void input();
    void search();
    void freq_word();
    void count_sentences();
    void convert();
    void count();
};
void pattern::input(){
    ifstream in("Input.txt");
    string d;
    getline(in,d);
    s+=d;
    while(getline(in,d)){
        s+='\n';
        s+=d;
    }
    cout<<s<<endl;
}
void pattern::search(){
    string e;
    cout<<"Enter word or pattern to be searched\n";
    cin>>e;
    int a=0,c=0;
    bool b=true;
    for(int i=0;i<s.length();i++){
        a=i;
        for(int j=0;j<e.length();j++){
            if(e[j]==s[a]){
                a++;
                b=true;
            }
            else{
                b=false;
                break;
            }
        }
        if(b){
            c=i;
            break;
        }
    }
    if(b){
        cout<<"Found at position "<<c<<endl;
    }
    else{
        cout<<"Not found\n";
    }
}
void pattern::freq_word(){
    int a=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '||s[i]=='\n'){
            a++;
        }
    }
    cout<<"The number of words are: "<<a<<endl;
}
void pattern::count_sentences(){
    int a=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            a++;
        }
    }
    cout<<"The number of sentences are: "<<a<<endl;
}
void pattern::convert(){
    stack<string> e;
    string f;
    for(int i=0;i<s.length();i++){
        f+=s[i];
        if(s[i]==' '||s[i]=='\n'||s[i]=='.'||s[i]==','){
            f.erase(remove(f.begin(),f.end(),s[i]),f.end());
            e.push(f);
            f.clear();
            continue;
        }
    }
    stack<string> ar;
    while(!e.empty()){
        ar.push(e.top());
        e.pop();
    }
    while(!ar.empty()){
        cout<<ar.top()<<endl;
        ar.pop();
    }
}
void pattern::count(){
    int a=0,para=1,chara=0;
    for(int i=0;i<s.length();i++){
        a=i;
        chara++;
        if(s[i]==' '||s[i]=='\n'){
            chara--;
            if(s[a]=='\n'&&s[a++]=='\n'){
                para++;
            }
            continue;
        }
    }
    cout<<"No. of characters are: "<<chara<<endl;
    freq_word();
    count_sentences();
    cout<<"No. of paragraphs are: "<<para<<endl;
}
int main(){
    int a;
    pattern p;
    while(1){
        cout<<"Enter 1 - input\n";
        cout<<"Enter 2 - search\n";
        cout<<"Enter 3 - frequency of each word\n";
        cout<<"Enter 4 - number of sentences\n";
        cout<<"Enter 5 - convertion into words\n";
        cout<<"Enter 6 - no. of all types\n";
        cout<<"Enter 7 - exit\n";
        cin>>a;
        switch(a){
            case 1:
            p.input();
            break;
            case 2:
            p.search();
            break;
            case 3:
            p.freq_word();
            break;
            case 4:
            p.count_sentences();
            break;
            case 5:
            p.convert();
            break;
            case 6:
            p.count();
            break;
            case 7:
            exit(0);
            break;
            default:
            cout<<"No match to your selection\n";
            break;
        }
    }
}
