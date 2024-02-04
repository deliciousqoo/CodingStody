/*
* 백준1874 스택으로 수열 만들기
* 자료구조 - 스택
* 20240205
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> arr(n, 0);
	stack<int> myStack;
	vector<char> ans;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int num = 1;
	bool resultCheck = true;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= num) {
			while (arr[i] >= num) {
				myStack.push(num);
				num++;
				ans.push_back('+');
			}
			myStack.pop();
			ans.push_back('-');
		}
		else
		{
			if (myStack.top() == arr[i]) {
				myStack.pop();
				ans.push_back('-');
			}
			else
			{
				cout << "NO";
				resultCheck = false;
				break;
			}
		}
	}

	if (resultCheck) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}

	return 0;
}