/*
* 백준9251
* 문자열
* 20240519
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> arr;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	arr.resize(s2.size() + 1);
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].resize(s1.size() + 1);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (i == 0 || j == 0) arr[i][j] = 0;
			else if (s1[j - 1] == s2[i - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
			else if (s1[j - 1] != s2[i - 1]) arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	}

	/*for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << arr[arr.size()-1][arr[0].size()-1];
	
	return 0;
}