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
            cout<<-1<<endl;
            return; //위치를 받았다는건 이미 있다는거!
        }
        int idx=find(parData,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return; //부모 노드가 없다는거 !
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
            return; //삭제하려는 값을 가진 노드가 없다는거
        }
        node *delNode=nodeList[idx];
        if(delNode==root){
            return; //삭제하려는게 루트인거
        }
        //멀쩡하게 삭제하는거
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
            cout<<-1<<endl;
            return;
        }
        node*curNode=nodeList[idx];
        cout<<curNode->parent->data<<endl;
    }


    void printChild(int data){
        int idx=find(data,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return;
        }
        bool a=false;
        vector<node*>& child=nodeList[idx]->childList;
        for(int i=0; i<child.size(); i++){
            cout<<child[i]->data<<" ";
            a=true;
        }
        if(a==false){
            cout<<-1<<endl;
        }
        cout<<endl;
    }

    void minChild(int x){
        int min;


        int idx=find(x,nodeList);
        if(idx==-1){
            cout<<-1<<endl;
            return;
        }

        vector<node*>& child=nodeList[idx]->childList;

        if(child.size()==0){
            cout<<-1<<endl;
            return;
        }

        min=child[0]->data;
        for(int i=1; i<child.size(); i++){
            if(min>child[i]->data){
                min=child[i]->data;
            }
        }
        cout<<min<<endl;


    }
};

int main(){
    Tree tr=Tree(1);

    int T;
    cin>>T;

    string a;
    int l,ll;

    for(int i=0; i<T; i++){
        cin>>a;

        if(a=="insert"){
            cin>>l>>ll;
            tr.insertNode(l,ll);
        }
        else if(a=="delete"){
            cin>>l;
            tr.deleteNode(l);
        }
        else if(a=="parent"){
            cin>>l;
            tr.printParent(l);
        }
        else if(a=="child"){
            cin>>l;
            tr.printChild(l);
        }
        else if(a=="minChild"){
            cin>>l;
            tr.minChild(l);
        }
    }
}