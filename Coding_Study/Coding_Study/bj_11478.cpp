/*
* 백준11478
* 문자열
* 20240521
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<string> s_arr;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			s_arr.push_back(s.substr(i, j));
		}
	}

	sort(s_arr.begin(), s_arr.end());

	int count = 0;
	for (int i = 0; i < s_arr.size(); i++)
	{
		if (i == s_arr.size() - 1)
		{
			if (s_arr[i] != s_arr[i - 1]) count++;
		}
		else
		{
			if (s_arr[i] != s_arr[i + 1]) count++;
		}
	}

	cout << count;

	return 0;
}