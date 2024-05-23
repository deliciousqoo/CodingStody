/*
* 백준10610
* 문자열
* 20240519
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	sort(s.begin(), s.end(), greater<int>());

	int total = 0;
	for (int i = 0; i < s.length()-1; i++)
	{
		total += s[i] - '0';
	}

	if (total % 3 == 0 && s[s.length()-1] == '0')
	{
		cout << s;
	}
	else
	{
		cout << -1;
	}

	return 0;
}