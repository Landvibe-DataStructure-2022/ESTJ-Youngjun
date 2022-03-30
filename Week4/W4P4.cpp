#include <iostream>
using namespace std;

struct node{
    int data;
    node*next;
};

class listQueue{
private:
    node *frontNode;
    node *rearNode;
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
    int front(){
        if(empty()){
            return -1;
        }
        return frontNode->data;
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
    int dequeue(){
        int a=frontNode->data;

        if(empty()){

            return 0;
        }
        node *curNode=frontNode;
        if(size()==1){
            frontNode=rearNode=NULL;
        }
        else{
            frontNode=frontNode->next;
        }
        delete curNode;
        n--;


        return a;
    }
};

int main(){
    int T;
    cin>>T;

    for(int i=0; i<T; i++){
        int N;
        cin>>N;

        listQueue *q1=new listQueue;
        listQueue *q2=new listQueue;

        for(int j=0; j<N; j++){
            int a;
            cin>>a;
            q1->enqueue(a);
        }
        for(int k=0; k<N; k++){
            int a;
            cin>>a;
            q2->enqueue(a);
        }
        int sum1,sum2;
        int point1,point2;
        sum1=sum2=point1=point2=0;

        for(int l=1; l<=N; l++){

            sum1=sum1+q1->dequeue();
            sum2=sum2+q2->dequeue();

            if(sum1>sum2){
                point1++;
                sum2=sum1-sum2;
                sum1=0;


            }
            else if(sum1<sum2){
                point2++;
                sum1=sum2-sum1;
                sum2=0;


            }
            else{
                sum1=sum2=0;

            }


        }



        if(point1>point2){
            cout<<point1<<endl;
        }
        else if(point1<point2){
            cout<<point2<<endl;
        }
        else{
            cout<<point1<<endl;
        }

        delete q1;
        delete q2;
    }
}

