/*
* 백준 10804 - 카드 역배치
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

	vector<int> arr(20);
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 1;
	}

	int start, end;
	for (int i = 0; i < 10; i++)
	{
		cin >> start >> end;
		reverse(arr.begin() + start - 1, arr.begin() + end);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}