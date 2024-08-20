/*
* 백준 10867 - 중복 빼고 정렬하기
* 20240816
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N; 
	
	vector<int> arr(N);

	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";

	return 0;
}