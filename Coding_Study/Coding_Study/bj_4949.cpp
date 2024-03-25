/*
* ¹éÁØ4949 ±ÕÇüÀâÈù ¼¼»ó
* ½ºÅÃ, Å¥, µ¦
* 20240318
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<int> myStack;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	while (true) {
		getline(cin, input);
		if (input == ".") {
			break;
		}

		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '[') {
				myStack.push(1);
			}
			else if (input[i] == ']') {
				if (myStack.empty() || myStack.top() != 1) myStack.push(3);
				else if (myStack.top() == 1) myStack.pop();
			}
			else if (input[i] == '(') {
				myStack.push(2);
			}
			else if (input[i] == ')') {
				if (myStack.empty() || myStack.top() != 2) myStack.push(4);
				else if (myStack.top() == 2) myStack.pop();
			}
		}

		if (myStack.empty()) cout << "yes\n";
		else cout << "no\n";

		myStack = {};
	}

	return 0;
}