#include <iostream>
using namespace std;

class Array{
private:
    int *arr;
    int arrSize;

public:
    Array(int sz){
        this->arrSize=sz;
        this->arr=new int[arrSize];
        for(int i=0; i<arrSize; i++){
            arr[i]=0;
        }
    }

    int at(int idx){
        return arr[idx];
    }

    void add(int idx,int value){
        for(int i=arrSize-2; i>=idx; i--){
            arr[i+1]=arr[i];
        }
        arr[idx]=value;
    }

    void set(int idx,int value){
        arr[idx]=value;
    }

    void print(){
        for(int i=0; i<arrSize; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void remove(int idx){
        for(int i=idx+1; i<arrSize; i++){
            arr[i-1]=arr[i];
        }
        arr[arrSize-1]=0;
    }

    void find(int value){
        int sum=0;
        for(int i=0; i<arrSize; i++){
            if(arr[i]==value){
                sum +=1;
            }
        }
        cout<<sum<<endl;
    }
};

int main(){
    int T,N;
    cin>>T>>N;

    Array arr=Array(N);

    string cmd;
    int index;
    int data;

    for(int i=0; i<T; i++){
        cin>>cmd;

        if(cmd=="add"){
            cin>>index>>data;
            arr.add(index,data);
        }
        else if(cmd=="remove"){
            cin>>index;
            arr.remove(index);
        }
        else if(cmd=="set"){
            cin>>index>>data;
            arr.set(index,data);
        }
        else if(cmd=="print"){
            arr.print();
        }
        else if(cmd=="find"){
            cin>>data;
            arr.find(data);
        }











    }
}