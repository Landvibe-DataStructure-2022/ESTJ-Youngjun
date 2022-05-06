#include<iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

class nodeList {
private:
    node* header;
    node* trailer;
    int n;


public:
    nodeList() {
        header = new node();
        trailer = new node();
        header->next = trailer;
        trailer->prev = header;
        header->prev = trailer->next = NULL;
        n = 0;
    }

    bool empty() {
        return (n == 0);
    }

    int size() {
        return n;
    }

    node* begin() {
        return header->next;
    }

    node* end() {
        return trailer;
    }


    void insert(node* pos, int data) {
        node* newNode = new node();
        newNode->data = data;
        newNode->prev = pos->prev;
        newNode->next = pos;
        pos->prev->next = newNode;
        pos->prev = newNode;
        n++;
    }

    bool erase(node* pos) {


        if (n == 0) {
            cout << "Empty" << endl;
            return false;
        }

        else if (pos == trailer) {
            return false;
        }

        else {
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;
            delete pos;
            n--;
            return true;
        }

    }

    void print() {

        if (empty()) {
            cout << "Empty" << endl;
            return;
        }

        node* curNode = new node();
        curNode = header->next;

        while (curNode != trailer) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }


    void upper(int e) {
        if (empty()) {
            cout << -1 << endl;
            return;
        }

        bool a = false;

        node* curNode = new node();
        curNode = this->begin();

        for (int i = 0; i < n; i++) {
            if (curNode->data > e) {
                cout << i << " ";
                a = true;
            }
            curNode=curNode->next;
        }


        if (a == false) {
            cout << -1 ;
        }

        cout<<endl;

    }
};


int main() {

    nodeList list;
    node* p = list.begin();


    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {

        string a;
        cin >> a;

        if (a == "begin") {
            p = list.begin();
        }
        if (a == "end") {
            p = list.end();
        }
        if (a == "insert") {
            int e;
            cin >> e;
            list.insert(p, e);
        }
        if (a == "erase") {
            if(list.erase(p)){
                p=list.begin();
            }
        }
        if (a == "nextP") {
            if (p != list.end()) {
                p = p->next;
            }
        }
        if (a == "prevP") {
            if (p != list.begin()) {
                p = p->prev;
            }
        }
        if (a == "print") {
            list.print();
        }
        if (a == "upper") {
            int e;
            cin >> e;
            list.upper(e);
        }






    }

}