#include<iostream>
#include<stdlib.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
class sorting{
    int ar[100000];
    int size;
    public:
    void input();
    void bubble();
    void insertion();
    void selection();
    void radix();
    int getMax();
    void shell();
    void display();
};
void sorting::input(){
    size=rand()%100000;
    for(int i=0;i<size;i++){
        ar[i]=rand()%100000;
    }
    cout<<"Array successfully created\n";
}
void sorting::bubble(){
    auto start = high_resolution_clock::now();
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(ar[j]>ar[j+1]){
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time = "<<duration.count()<<"microseconds"<<endl;
}
void sorting::insertion(){
    auto start = high_resolution_clock::now();
    for(int i=1;i<size;i++){
        int temp=ar[i];
        int j=i-1;
        while(temp<ar[j] && j>=0){
            ar[j+1]=ar[j];
            --j;
        }
        ar[j+1]=temp;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time = "<<duration.count()<<"microseconds"<<endl;
}
void sorting::selection(){
    auto start = high_resolution_clock::now();
    for(int i=0;i<size-1;i++){
        int temp=i;
        for(int j=i+1;j<size;j++){
            if(ar[j]<ar[temp]){
                temp=j;
            }
            int temps=ar[temp];
            ar[temp]=ar[i];
            ar[i]=temps;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time = "<<duration.count()<<"microseconds"<<endl;
}
void sorting::shell(){
    auto start = high_resolution_clock::now();
    for(int i=size/2;i>0;i/=2) {
    for (int j=i;j<size;j++) {
      int temp=ar[j];
      int b;
      for (b=j;b>=i&&ar[b-i]>temp;b-=i) {
        ar[b]=ar[b-i];
      }
      ar[b]=temp;
    }
  }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time = "<<duration.count()<<"microseconds"<<endl;
}
void countingSort(int array[], int size, int place) {
  const int max=10;
  int output[size];
  int count[max];
  for(int i=0;i<max;++i)
    count[i]=0;
  for(int i=0;i<size;i++)
    count[(array[i]/place)%10]++;
  for (int i = 1; i < max; i++)
    count[i]+=count[i-1];
  for (int i=size-1;i>=0;i--) {
    output[count[(array[i]/place)%10]-1]=array[i];
    count[(array[i]/place)%10]--;
  }
  for (int i=0;i<size;i++)
    array[i]=output[i];
}
int sorting::getMax() {
  int max=ar[0];
  for (int i=1;i<size;i++)
    if (ar[i]>max)
      max=ar[i];
  return max;
}
void sorting::radix() {
    auto start = high_resolution_clock::now();
    int max = getMax();
    for(int place=1;max/place>0;place*=10)
    countingSort(ar, size, place);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"Time = "<<duration.count()<<"microseconds"<<endl;
}
void sorting::display(){
    for(int i=0;i<size;i++){
        cout<<ar[i]<<endl;
    }
}
int main(){
    sorting s;
    int a;
    while(1){
        cout<<"Enter 1 - input\n";
        cout<<"Enter 2 - Bubble sort\n";
        cout<<"Enter 3 - Insertion sort\n";
        cout<<"Enter 4 - selection sort\n";
        cout<<"Enter 5 - radix sort\n";
        cout<<"Enter 6 -shell sort\n";
        cout<<"Enter 7 - display array\n";
        cout<<"Enter 8 - exit\n";
        cin>>a;
        switch(a){
            case 1:
            s.input();
            break;
            case 2:
            s.bubble();
            break;
            case 3:
            s.insertion();
            break;
            case 4:
            s.selection();
            break;
            case 5:
            s.radix();
            break;
            case 6:
            s.shell();
            break;
            case 7:
            s.display();
            break;
            case 8:
            exit(0);
            break;
            default:
            cout<<"No match to your selection\n";
            break;
        }
    }
}