#include<iostream>
using namespace std;
class queue{
    public:
    int size;
    int f,r;
    int *arr;
};
int isEmpty(queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        cout<<"This Queue is full\n";
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        cout<<"This Queue is empty\n";
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
class traverse{
    public:
    int visited[7] = {0,0,0,0,0,0,0};
    char ar[7]={'a','b','c','d','e','f','g'};
    int A [7][7] = {
        {0,1,4,0,0,0,0},
        {1,0,2,3,10,0,0},
        {4,2,0,6,0,0,3},
        {0,3,6,0,5,0,1},
        {0,10,0,5,0,7,2},
        {0,0,0,0,7,0,5}, 
        {0,0,3,1,2,5,0} 
    };
    int as=0;
    void DFS(int);
    void BFS();
    void display();
};
void traverse::DFS(int i){
    cout<<ar[i]<<" ";
    visited[i] = 1;
    for (int j = 0; j < 7; j++){
        if(A[i][j]>=1 && !visited[j]){
            DFS(j);
        }
    }
}
void traverse::BFS(){
    for(int i=0;i<7;i++){
        visited[i] = 0;
    }
    queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = new int[q.size];
    int b=0;
    int node;
    int i = 1;
    cout<<ar[i]<<" ";
    visited[i] = 1;
    enqueue(&q, i); 
    while (!isEmpty(&q)){
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++){
            if(A[node][j] >=1 && visited[j] == 0){
                cout<<ar[j]<<" ";
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}
void traverse::display(){
	for(int i=0;i<7;i++){
        cout<<ar[i]<<"--> ";
        for(int j=0;j<7;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){ 
    traverse t;
    cout<<"The graph is:-\n";
    t.display();
    cout<<"DFS Traversal is:-\n";
    t.DFS(0);
    cout<<endl;
    cout<<"BFS Traversal is:-\n";
    t.BFS();
    return 0;
}
