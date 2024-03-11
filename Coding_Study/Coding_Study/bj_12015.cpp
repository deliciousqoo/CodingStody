/*
* 백준12015
* 이분탐색
* 20240311
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
vector<int> arr;
stack<int> myStack;

/*
void Binary_Search(int target) {
	int start = 0;
	int end = arr.size() - 1;
	
	while (start <= end) {
		int mid = (start + end) / 2;
		if(arr[mid] >= )
	}
}*/

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	int input, cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (i == 0) {
			myStack.push(input);
			cnt++;
		}
		else
		{
			while (myStack.top() > input) {
				cnt--;
				myStack.pop();
			}
			myStack.push(input);
			cnt++;
		}
	}



	return 0;
}