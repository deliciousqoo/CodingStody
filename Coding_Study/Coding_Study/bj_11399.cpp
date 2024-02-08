/*
* 백준11399 ATM
* 삽입 정렬
* 20240207
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int insert_index;
	int temp;
	for (int i = 1; i < N; i++) {
		int insert_index = i;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				insert_index = j;
				break;
			}
		}

		temp = arr[i];
		for (int j = i; j > insert_index; j--) {
			arr[j] = arr[j - 1];
		}
		arr[insert_index] = temp;
	}
	
	int answer = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		arr[i] = arr[i] + arr[i - 1];
		answer += arr[i];
	}

	cout << answer;

	return 0;
}