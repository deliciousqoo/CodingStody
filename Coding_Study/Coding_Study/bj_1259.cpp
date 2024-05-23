/*
* 백준1259
* 문자열
* 20240519
*/
#include <iostream>

using namespace std;

int main()
{
	string s;
	while (true)
	{
		cin >> s;
		if (s == "0") break;

		bool check = false;
		for (int i = 0; i < s.size() / 2; i++)
		{
			if (s[i] != s[s.size() - 1 - i]) check = true;
		}

		if (!check) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}

	return 0;
}