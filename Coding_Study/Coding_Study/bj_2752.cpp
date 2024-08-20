/*
* 백준 2752 - 세수정렬
* 20240815
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

	vector<int> arr(3);
	
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}