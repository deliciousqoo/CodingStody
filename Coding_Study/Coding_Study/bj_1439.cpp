/*
* 백준1439
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

	int count0 = 0, count1 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0' && s[i] != s[i + 1]) count0++;
		else if (s[i] == '1' && s[i] != s[i + 1]) count1++;
	}

	cout << min(count0, count1);

	return 0;
}