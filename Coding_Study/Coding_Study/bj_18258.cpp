/*
* 백준18258 큐 2
* 스택, 큐, 덱
* 20240325
*/
#include <iostream>
#include <queue>

using namespace std;
queue<int> myQueue;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	queue<int> myQueue;

	string command;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> input;
			myQueue.push(input);
		}
		else if (command == "pop") {
			if (myQueue.empty()) cout << "-1\n";
			else {
				cout << myQueue.front() << "\n";
				myQueue.pop();
			}
		}
		else if (command == "size") {
			cout << myQueue.size() << "\n";
		}
		else if (command == "empty") {
			cout << myQueue.empty() << "\n";
		}
		else if (command == "front") {
			if (myQueue.empty()) cout << "-1\n";
			else cout << myQueue.front() << "\n";
		}
		else if (command == "back") {
			if (myQueue.empty()) cout << "-1\n";
			else cout << myQueue.back() << "\n";
		}
	}
	
	return 0;
}