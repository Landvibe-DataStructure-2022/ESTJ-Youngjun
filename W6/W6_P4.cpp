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



class Tree{

private:
    node *root;
    vector<node*>nodeList;
    int find(int data,vector<node*>& list){
        for(int i=0; i<list.size(); i++)
        {
            if(list[i]->data==data)return i;
        }
        return -1;
    }

public:
    Tree(int data){
        root=new node(data,NULL);
        nodeList.push_back(root);
    }
    void insertNode(int parData,int data){
        if(find(data,nodeList)!=-1){
            return;
        }
        int idx=find(parData,nodeList);
        if(idx==-1){
            return;
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
            return;
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

        vector<node*>& child=parNode->childList;
        child.erase(child.begin()+find(data,child));
        delete nodeList[idx];
        nodeList.erase(nodeList.begin()+idx);
        return;
    }
    void printParent(int data){
        int idx=find(data,nodeList);
        if(idx==-1){
            return;
        }
        node*curNode=nodeList[idx];
        cout<<curNode->parent->data<<endl;
    }


    void printChild(int data){
        int idx=find(data,nodeList);
        if(idx==-1){
            return;
        }
        vector<node*>& child=nodeList[idx]->childList;
        for(int i=0; i<child.size(); i++){
            cout<<child[i]->data<<" ";
        }
        cout<<endl;
    }

    int aa(int value){
        int count=1;
        if(value==1){
            return 0;
        }
        else{
            int idx=find(value,nodeList);
            if(nodeList[idx]->parent==root){
                return count;
            }
            else{

                return count+aa(nodeList[idx]->parent->data);
            }
        }



    }
};

int main(){
    int N,M;
    cin>>N>>M;
    Tree t=Tree(1);
    int x,y;

    for(int i=1; i<N; i++)
    {
        cin>>x>>y;
        t.insertNode(x,y);
    }

    //여기까지 노드 만들었어
    int value;
    for(int i=1; i<=M; i++){
        cin>>value;
        cout<<t.aa(value)<<endl;




    }








}