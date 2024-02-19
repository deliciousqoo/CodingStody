/*
* 백준11650 좌표 정렬하기
* 정렬
* 20240219
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

bool cmp(p p1, p p2) {
	if (p1.first == p2.first) {
		if (p1.second < p2.second) return true;
		else return false;
	}
	else
	{
		if (p1.first < p2.first) return true;
		else return false;
	}
}

int main() {

	int N;
	cin >> N;
	
	vector<p> arr;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}