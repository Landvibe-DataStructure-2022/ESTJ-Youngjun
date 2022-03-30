#include <iostream>
using namespace std;

struct node{
    int data;
    node*next;
};

class listQueue{
private:
    node*frontNode;
    node* rearNode;
    int n;



public:
    listQueue(){
        frontNode=NULL;
        rearNode=NULL;
        n=0;
    }

    bool empty(){
        return(n==0);
    }

    int size(){
        return n;
    }

    void front(){
        if(empty()){
            cout<<"Empty"<<endl;
        }
        else{
            cout<<frontNode->data<<endl;
        }
    }

    void rear(){
        if(empty()){
            cout<<"Empty"<<endl;
        }
        else{
            cout<<rearNode->data<<endl;
        }
    }

    void enqueue(int data){
        node *newNode=new node;
        newNode->data=data;
        newNode->next=NULL;
        if(empty()){
            frontNode=rearNode=newNode;
        }
        else{
            rearNode->next=newNode;
            rearNode=newNode;
        }
        n++;
    }

    void dequeue(){
        if(empty()){
            cout<<"Empty"<<endl;
            return;
        }
        node* curNode=frontNode;
        cout<<curNode->data<<endl;
        if(size()==1){
            frontNode=rearNode=NULL;
        }
        else{
            frontNode=frontNode->next;
        }
        delete curNode;
        n--;
    }
};

int main(){


    int T;
    cin>>T;
    string a;
    listQueue lq;

    for(int i=0; i<T; i++){

        cin>>a;
        if(a=="enqueue"){
            int value;
            cin>>value;
            lq.enqueue(value);
        }
        if(a=="dequeue"){
            lq.dequeue();
        }
        if(a=="isEmpty"){
            if(lq.empty()){
                cout<<"True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }
        }
        if(a=="size"){
            cout<<lq.size()<<endl;
        }
        if(a=="front"){
            lq.front();
        }
        if(a=="rear"){
            lq.rear();
        }





    }






}