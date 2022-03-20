#include <iostream>
using namespace std;

class st{

private:
    int size;
    int maxIndex;

    int *arr=new int[size];

public:
    st(int s)
    {
        this->size=s;
        maxIndex=-1;
        for(int i=0; i<=maxIndex; i++){
            arr[i]=NULL;
        }
    }

    //empty 0,1 return
    bool em(){
        if(maxIndex==-1){
            return 1;
        }
        else
        {
            return 0;
        }

    }

    //empty cout
    void empty(){
        if(maxIndex==-1){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }

    void top(){
        if(this->em()==1){
            cout<<-1<<endl;
        }
        else{
            cout<<arr[this->maxIndex]<<endl;
        }

    }

    void push(int value){
        if(maxIndex+1==size){
            cout<<"FULL"<<endl;
        }
        else {
            arr[this->maxIndex + 1] = value;
            maxIndex++;
        }
    }

    void pop(){
        if(em()){
            cout<<-1<<endl;
        }
        else {
            cout << arr[maxIndex] << endl;
            arr[this->maxIndex] = NULL;
            maxIndex--;
        }
    }

    //확인용
    void print(){
        for(int i=0; i<= maxIndex; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


int main(){
    int t,cmd;
    cin>>t>>cmd;

    st mystack(t);
    for(int i=0; i<cmd; i++){

        string a;
        cin>>a;

        if(a=="empty"){
            mystack.empty();
        }
        if(a=="top"){
            mystack.top();
        }
        if(a=="push"){
            int val;
            cin>>val;
            mystack.push(val);
        }
        if(a=="pop"){
            mystack.pop();
        }
        if(a=="print"){
            mystack.print();
        }

    }

}