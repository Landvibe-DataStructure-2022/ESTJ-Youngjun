#include <iostream>
using namespace std;


//주의
//리스트 헤더 트레일러 제외 노드가 1개인경우 앞뒤값 없으니까 0 출력해야됨 출력 없으면 오답


struct node{
    int data;
    node *prev;
    node *next;
};

class nodeList{
private:
    node *header;
    node *trailer;
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
    int large;
    int small;


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




        //각 노드로 설정하고 앞뒤 현재 값 받아와서 계산?
        p=list->begin();
        while(p!=list->end()){
            if(list->size()==1){
                cout<<0<<" ";
            }
            else if(p->prev->prev==NULL){
                //맨 앞인 경우
                if(p->data>p->next->data){
                    cout<<p->data-p->next->data<<" ";
                }
                else{
                    cout<<p->next->data-p->data<<" ";
                }
            }
            else if(p==list->end()->prev){
                if(p->prev->data>p->data){
                    cout<<p->prev->data-p->data<<" ";
                }
                else{
                    cout<<p->data-p->prev->data<<" ";
                }
            }
            else{
                // 3개 나오는 경우인데
                large=small=p->prev->data;
                if(p->data>large){
                    large=p->data;
                }
                if(p->next->data>large){
                    large=p->next->data;
                }
                if(p->data<small){
                    small=p->data;
                }
                if(p->next->data<small){
                    small=p->next->data;
                }
                cout<<large-small<<" ";
            }





            p=p->next;

        }
        cout<<endl;

    }
}



