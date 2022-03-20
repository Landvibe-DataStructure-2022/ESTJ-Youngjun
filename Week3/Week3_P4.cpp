#include <iostream>
using namespace std;

class stack{

private:

    int maxIdx;
    int arr[100];

public:
    //생성자
    stack st(){
        for(int i=0; i<100; i++){
            this->arr[i]=NULL;
        }
        //아무것도 안들어가 있으니까 가장 높은 인덱스가 -1
        //하나 들어가있으면 0
        this->maxIdx=-1;
    }

    //push
    void push(int a){
        arr[maxIdx+1]=a;
        maxIdx++;
    }

    //empty
    bool empty(){
        if(maxIdx==-1){
            return 1;
        }
        else{
            return 0;
        }
    }

    //top
    int top(){
        return arr[maxIdx];
    }

    //pop
    void pop(){
        arr[maxIdx]=NULL;
        maxIdx--;
    }

    int value(int i){
        return arr[i];
    }

};

int main(){
    stack myst;
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        string a;
        cin>>a;

        for(int i=0; i<a.size(); i++){
            if(a[i]=='+'){
                int later=myst.top();
                myst.pop();
                int early=myst.top();
                myst.pop();
                myst.push(early+later);
            }
            else if(a[i]=='-'){
                int later=myst.top();
                myst.pop();
                int early=myst.top();
                myst.pop();
                myst.push(early-later);
            }
            else if(a[i]=='*'){
                int later=myst.top();
                myst.pop();
                int early=myst.top();
                myst.pop();
                myst.push(early*later);
            }
            else{

                myst.push(a[i]-'0');
            }
        }

        cout<<myst.top()<<endl;






    }
}