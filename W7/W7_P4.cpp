#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*>childList;
	int value;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
		value = 0;
	}
};

class Tree {
public:
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

	int postorder(node *curNode) {
		


		int sum = curNode->value;
		for (int i = 0; i < curNode->childList.size(); i++) {
			sum=sum+postorder(curNode->childList[i]);
		}
		return sum;
	}
	
	void insertValue(int data,int value) {
		int idx = find(data, nodeList);
		nodeList[idx]->value = value;
	}


};


int main() {
	Tree t = Tree(1);
	int N, M;
	cin >> N >> M;
	int parData, data, value;

	for (int i = 1; i < N; i++) {
		cin >> parData >> data;
		t.insertNode(parData, data);
	}
	
	for (int i = 0; i < N; i++) {
		cin >> data >> value;
		t.insertValue(data, value);
	}



	for (int i = 0; i < M; i++) {
		cin >> data;
		
		cout << t.postorder(t.nodeList[t.find(data, t.nodeList)]) << endl;
	}






	//용량계산

}

