/*
* 정렬1181 단어 정렬
* 정렬
* 20240219
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
	if (s1.length() < s2.length()) { return true; }
	else if (s1.length() > s2.length()) { return false; }
	else
	{
		if (s1 < s2) return true;
		else return false;
	}
}

int main() {

	int N;
	cin >> N;

	vector<string> arr;

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end(), cmp);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}