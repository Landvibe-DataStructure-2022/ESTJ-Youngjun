#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*>childList;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;
	vector<node*>nodeList;

	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == data) {
				return i;
			}
		}
		return -1;
	}

public:


	Tree(int data) {
		root = new node(data, NULL);
		nodeList.push_back(root);
	}

	void insertNode(int parData, int data) {
		if (find(data, nodeList) != -1) {
			return;            //-1이면 데이터가 없는거 -1이 아니다 니까 있는거 이미
		}

		int idx = find(parData, nodeList);
		if (idx == -1) {
			return;           //-1이면 부모노드 없음
		}

		node* parNode = nodeList[idx];
		node* newNode = new node(data, parNode);
		parNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
		return;
	}

	void preorder(node* curNode) {
		cout << curNode->data << " ";
		for (int i = 0; i < curNode->childList.size(); i++) {
			preorder(curNode->childList[i]);
		}
	}

	void postorder(node* curNode, int dep = 0) {
		
		for (int i = 0; i < curNode->childList.size(); i++) {
			postorder(curNode->childList[i],dep+1);
		}
		cout << dep << " ";
		//cout << curNode->data << " ";
	}

	
	node *r() {
		return root;
	}

};


int main() {
	
	int Test;
	cin >> Test;
	int N, parData, data;
	for (int i = 0; i < Test; i++) {
		Tree *t = new Tree(1);
		cin >> N;
		for (int i = 1; i < N; i++) {
			cin >> parData >> data;
			t->insertNode(parData, data);
		}
		//입력까지 완료

		t->postorder(t->r());
		cout << endl;




		delete t;


	}
}

