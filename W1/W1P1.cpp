#include<iostream>
using namespace std;

class Array {

private:
	int* arr;
	int arrSize;

public:
	Array(int sz) {
		this->arrSize = sz;
		this->arr = new int[arrSize];

		for (int i = 0; i < sz; i++) {
			arr[i] = 0;
		}


	}

	void add() {
		int idx;
		int value;
		cin >> idx >> value;

		for (int i = arrSize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}	
	
	void remove() {
		int idx;
		cin >> idx;

		for (int i = idx + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}

	void set() {
		int idx;
		int value;
		cin >> idx >> value;
		arr[idx] = value;
	}

	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void find() {
		int value;
		int sum = 0;
		cin >> value;

		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == value) {
				sum = sum + 1;
			}
		}
		cout << sum << endl;
	}


	/*int at(int idx) {
		return arr[idx];
	}


	void add(int idx, int value) {
		for (int i = arrSize - 2; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void set(int idx, int value) {
		arr[idx] = value;
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void remove(int idx) {
		for (int i = idx + 1; i < arrSize; i++) {
			arr[i - 1] = arr[i];
		}
		arr[arrSize - 1] = 0;
	}*/

};



	int main() {
		int T;
		int s;
		string a;

		cin >> T >> s;

		Array arr(s);

		for (int i = 0; i < T; i++) {
			cin >> a;

			if (a == "add") {
				arr.add();
			}
			if (a == "remove") {
				arr.remove();
			}
			if (a == "set") {
				arr.set();
			}
			if (a == "print") {
				arr.print();
			}
			if (a == "find") {
				arr.find();
			}

			
		}


	}



