/*
* 백준14425 문자열 집합
* 집합과 맵
* 20240229
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(vector<string> arr, string target) {
	int start = 0;
	int end = arr.size() - 1;
	int mid;

	while (end - start > 0) {
		mid = (start + end) / 2;
		if (arr[mid] == target) return true;
		else if(arr[mid])
	}
}

int main() {

	int N, M;
	cin >> N >> M;
	
	vector<vector<string>> S;

	S.resize(26);

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		S[temp[0] - 'a'].push_back(temp);
	}

	int count = 0;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		for (int j = 0; j < S[temp[0]-'a'].size(); j++) {
			if () count++;
		}
	}

	cout << count;

	return 0;
}