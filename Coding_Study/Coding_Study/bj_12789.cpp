/*
* 백준12789 도키도키 간식드리미
* 스택, 큐, 덱
* 20240325
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	queue<int> myQueue;
	stack<int> myStack;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		myQueue.push(input);
	}
	
	int count = 1;
	for (int i = 0; i < N; i++) {
		if (myQueue.front() == count) {
			myQueue.pop();
			count++;
		}
		else
		{
			myStack.push(myQueue.front());
			myQueue.pop();
		}

		while (!myStack.empty()) {
			if (myStack.top() != count) break;
			myStack.pop();
			count++;
		}
	}

	if (myStack.size() == 0) cout << "Nice";
	else cout << "Sad";

	return 0;
}