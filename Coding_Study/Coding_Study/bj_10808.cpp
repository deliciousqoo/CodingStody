/*
* ����10808
* ���ڿ�
* 20240519
*/
#include <iostream>
#include <map>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int alphabet[26] = { 0, };

	for (int i = 0; i < s.size(); i++)
	{
		alphabet[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " ";
	}

	return 0;
}