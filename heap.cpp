#include<iostream>
#include<vector>
using namespace std;
class bheap{
    vector<int> heap;
    int choice;
    public:
    int par(int);
    void input(){
        cout<<"Enter 1 - min heap and 2 - max heap\n";
        cin>>choice;
    }
    void heaps_min(int);
    void heaps_max(int);
    void insert(int);
    void display();
    void element();
    int size();
};
int bheap::size(){
    return heap.size();
}
void bheap::insert(int a){
    heap.push_back(a);
    if(choice==1){
        heaps_min(heap.size()-1);
    }
    else if(choice==2){
        heaps_max(heap.size()-1);
    }
}
void bheap::display(){
    cout<<"The heap is as: ";
    for(auto i=heap.begin();i!=heap.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}
void bheap::element(){
    if(choice==1){
        cout<<"Minimum element is:-\n";
    }
    else if(choice==2){
        cout<<"Maximum element is:-\n";
    }
    cout<<heap.front()<<endl;
}
int bheap::par(int a){
    int p=(a-1)/2;
    if(a==0){
        return -1;
    }
    else{
        return p;
    }
}
void bheap::heaps_min(int a){
    if(a>=0&&par(a)>=0&&heap[par(a)]>heap[a]) {
      int temp=heap[a];
      heap[a]=heap[par(a)];
      heap[par(a)]=temp;
      heaps_min(par(a));
    }
}
void bheap::heaps_max(int a){
    if(a>=0&&par(a)>=0&&heap[par(a)]<heap[a]) {
      int temp=heap[a];
      heap[a]=heap[par(a)];
      heap[par(a)]=temp;
      heaps_max(par(a));
    }
}
int main(){
    bheap b;
    b.input();
    b.insert(97);
    b.insert(88);
    b.insert(95);
    b.insert(66);
    b.insert(55);
    b.insert(95);
    b.insert(48);
    b.insert(60);
    b.insert(45);
    b.insert(48);
    b.insert(55);
    b.insert(62);
    b.insert(77);
    b.insert(25);
    b.insert(38);
    b.insert(18);
    b.insert(40);
    b.insert(38);
    cout<<"Hash map is: \n";
    b.display();
    b.element();
    return 0;
}