/*
* 백준17298 오큰수 구하기
* 자료구조 - 스택
* 20240205
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> arr(N, 0);
	vector<int> ans(N, 0);
	stack<int> myStack;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	myStack.push(0);
	for (int i = 1; i < N; i++) {
		if (arr[myStack.top()] < arr[i]) {
			for (int j = 0; j < myStack.size(); j++) {
				if (arr[myStack.top()] >= arr[i]) break;
				ans[myStack.top()] = arr[i];
				myStack.pop();
				j--;
			}
			myStack.push(i);
		}
		else {
			myStack.push(i);
		}
	}

	while (!myStack.empty()) {
		int index = myStack.top();
		myStack.pop();
		ans[index] = -1;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}