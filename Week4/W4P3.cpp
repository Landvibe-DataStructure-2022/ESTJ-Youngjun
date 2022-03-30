#include <iostream>
using namespace std;

class arrayQueue{
private:
    int *arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int n;

public:
    arrayQueue(int capacity){
        this->capacity=capacity;
        arr=new int[capacity];
        frontIndex=rearIndex=0;
        n=0;
    }
    bool empty(){
        return (n==0);
    }
    int size(){
        return n;
    }
    void front(){
        if(empty()){
            cout<<"Empty"<<endl;
        }
        else {
            cout << arr[frontIndex]<<endl;
        }
    }
    void rear(){
        if(empty()){
            cout<<"Empty"<<endl;
        }
        else{
            if(rearIndex-1<0){
                cout<<arr[capacity-1]<<endl;
            }
            else{
                cout<<arr[rearIndex-1]<<endl;
            }
        }
    }
    void enqueue(int data){
        if(size()==capacity){
            cout<<"Full"<<endl;
        }
        else {
            arr[rearIndex] = data;
            rearIndex = (rearIndex + 1) % capacity;
            n++;
        }
    }
    void dequeue(){
        if(empty()){
            cout<<"Empty"<<endl;
        }
        else{
            cout<<arr[frontIndex]<<endl;
            frontIndex=(frontIndex+1)%capacity;
            n--;
        }

    }
};


int main(){
    int N,T;
    cin>>N>>T;

    arrayQueue aa(N);


    for(int i=0; i<T; i++){

        string a;
        cin>>a;

        if(a=="size"){
            cout<<aa.size()<<endl;
        }
        if(a=="isEmpty"){
            if(aa.empty()){
                cout<<"True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }
        }
        if(a=="front"){
            aa.front();
        }
        if(a=="rear"){
            aa.rear();
        }
        if(a=="enqueue"){
            int value;
            cin>>value;
            aa.enqueue(value);
        }
        if(a=="dequeue"){
            aa.dequeue();
        }
    }
}