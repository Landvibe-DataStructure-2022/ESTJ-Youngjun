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

    void shift(){
        int temp=arr[0];
        for(int i=0; i<arrSize-1; i++){
            arr[i]=arr[i+1];
        }
        arr[arrSize-1]=temp;
    }

    void reverse(int s,int e){
        int *tempArr=new int[e-s+1];
        for(int i=0; i<e-s+1; i++){
            tempArr[i]=arr[s+i];
        }

        for(int i=0; i<e-s+1; i++){
            arr[s+i]=tempArr[e-s-i];
        }
        delete tempArr;
    }
};

int main() {
    int T,N;
    int value;
    int left;
    int start,end;
    cin>>T>>N;

    Array arr=Array(N);
    for(int i=0; i<N; i++){
        cin>>value;
        arr.add(i,value);
    }

    string cmd;
    for(int i=0; i<T; i++){
        cin>>cmd;


        if(cmd=="shift"){
            cin>>left;
            for(int k=0; k<left; k++){
                arr.shift();
            }
        }
        else if(cmd=="print"){
            arr.print();
        }
        else if(cmd=="reverse"){
            cin>>start>>end;
            arr.reverse(start,end);
        }

    }


}