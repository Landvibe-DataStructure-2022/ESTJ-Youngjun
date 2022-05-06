#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    node *parent;
    vector<node*>childList;
    node(int data,node*parent){
        this->data=data;
        this->parent=parent;
    }
};

class Tree {
private:
    node*root;
    vector<node*>nodeList;
    int find(int data,vector<node*>&list){
        for(int i=0; i<list.size(); i++){
            if(list[i]->data==data){
                return i;
            }
        }
        return -1;
    }

public:
    Tree(int data){
        root=new node(data,NULL);
        nodeList.push_back(root);
    }

    void insertNode(int parent,int data){

        if(find(data,nodeList)!=-1){
            cout<<-1<<endl;
            return;//이미 있음
        }
        int idx=find(parent,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return; //부모가 없음
        }

        node *parNode=nodeList[idx];
        node *newNode=new node(data,parNode);
        parNode->childList.push_back(newNode);
        nodeList.push_back(newNode);
        return;
    }


    void deleteNode(int data){
        int idx=find(data,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return; //지우려는 노드 못찾음
        }

        node *delNode=nodeList[idx];
        if(delNode==root){
            return;
        }

        node *parNode=delNode->parent;

        for(int i=0; i<delNode->childList.size(); i++){
            parNode->childList.push_back(delNode->childList[i]);
            delNode->childList[i]->parent=parNode;
        }

        vector<node*>&child = parNode->childList;
        child.erase(child.begin()+find(data,child));
        delete nodeList[idx];
        nodeList.erase(nodeList.begin()+idx);
        return;

    }

    void printParent(int data){
        int idx=find(data,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return;
        }
        cout<<nodeList[idx]->parent->data<<endl;
    }

    void printChild(int data){
        int idx=find(data,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return;
        }
        if(nodeList[idx]->childList.size()==0){
            cout<<-1<<endl;
            return;
        }

        for(int i=0; i<nodeList[idx]->childList.size(); i++){
           cout<<nodeList[idx]->childList[i]->data<<" ";
        }
        cout<<endl;
    }

    void maxChild(int x){
        int idx=find(x,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return;
        }
        if(nodeList[idx]->childList.size()==0){
            cout<<-1<<endl;
            return;
        }

        int max=nodeList[idx]->childList[0]->data;
        for(int i=1; i<nodeList[idx]->childList.size(); i++){
            if(nodeList[idx]->childList[i]->data>max){
                max=nodeList[idx]->childList[i]->data;
            }
        }
        cout<<max<<endl;

    }
};

int main(){
    Tree *t=new Tree(1);

    int T,x,y;
    cin>>T;

    string cmd;
    for(int i=0; i<T; i++){
        cin>>cmd;

        if(cmd=="insert"){
            cin>>x>>y;
            t->insertNode(x,y);
        }
        else if(cmd=="parent"){
            cin>>x;
            t->printParent(x);
        }
        else if(cmd=="delete"){
            cin>>x;
            t->deleteNode(x);
        }
        else if(cmd=="child"){
            cin>>x;
            t->printChild(x);
        }
        else if(cmd=="maxChild"){
            cin>>x;
            t->maxChild(x);
        }
    }
}
