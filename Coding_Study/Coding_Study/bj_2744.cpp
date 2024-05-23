/*
* 백준1764
* 문자열
* 20240519
*/
#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 'a') s[i] = tolower(s[i]);
		else s[i] = toupper(s[i]);
	}

	cout << s;

	return 0;
}