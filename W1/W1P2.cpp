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
		
			cin >> arr[i];
		}


	}

	void shift() {
		int d;
		cin >> d;
		for (int i = 0; i < d; i++) {

			//여기에 한자리씩 당기기 구현
			int temp = arr[0];
			for (int i = 0; i < arrSize-1; i++) {
				arr[i] = arr[i + 1];
			}
			arr[arrSize - 1] = temp;
		}
		
	}

	void reverse() {
		int i;
		int j;
		cin >> i >> j;
		
		while (1) {
			
			int temp = arr[j];

			arr[j] = arr[i];
			arr[i] = temp;
			i = i + 1;
			j = j - 1;

			if (j - i < 1) {
				break;
			}
		}


	}


	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
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

			if (a == "shift") {
				arr.shift();
			}
			if (a == "reverse") {
				arr.reverse();
			}
			if (a == "print") {
				arr.print();
			}

			
		}


	}



