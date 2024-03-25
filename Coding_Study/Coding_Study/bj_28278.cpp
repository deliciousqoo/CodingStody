/*
* 백준28278 스택 2
* 스택, 큐, 덱
* 20240318
*/
#include <iostream>
#include <stack>

using namespace std;
stack<int> myStack;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;

		switch (input) {
			case 1:
				cin >> input;
				myStack.push(input);
				break;
			case 2:
				if (!myStack.empty()) {
					cout << myStack.top() << "\n";
					myStack.pop();
				}
				else
				{
					cout << -1 << "\n";
				}
				break;
			case 3:
				cout << myStack.size() << "\n";
				break;
			case 4:
				if (!myStack.empty()) {
					cout << 0 << "\n";
				}
				else {
					cout << 1 << "\n";
				}
				break;
			case 5:
				if (!myStack.empty()) {
					cout << myStack.top() << "\n";
				}
				else {
					cout << -1 << "\n";
				}
				break;
		}
	}

	return 0;
}