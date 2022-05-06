#include <iostream>
using namespace std;

struct node{
    int data;
    node *prev;
    node *next;
};

class nodeList{
private:
    node *header;
    node*trailer;
    int n;

public:
    nodeList(){
        header=new node();
        trailer=new node();
        header->next=trailer;
        trailer->prev=header;
        header->prev=trailer->next=NULL;
    }

    bool empty(){
        return(n==0);
    }

    int size(){
        return n;
    }

    node* begin(){
        return header->next;
    }

    node*end(){
        return trailer;
    }

    void insert(node *pos, int data){
        node *newNode=new node();
        newNode->data=data;
        newNode->prev=pos->prev;
        newNode->next=pos;
        pos->prev->next=newNode;
        pos->prev=newNode;
        n++;
    }

    void insertBack(int data){
        insert(end(),data);
    }



};

int main(){
    int N;
    cin>>N;
    int data;

    for(int i=0; i<N; i++){
        nodeList *list=new nodeList();
        node *p;

        int size;
        cin>>size;

        p=list->end();
        for(int j=0; j<size; j++){
            cin>>data;
            list->insertBack(data);
        }





    }
}



