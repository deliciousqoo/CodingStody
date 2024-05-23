/*
* 백준1032
* 문자열
* 20240519
*/
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	string org_str;
	cin >> org_str;

	string temp;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> temp;
		for (int j = 0; j < org_str.size(); j++)
		{
			if (org_str[j] != temp[j]) org_str[j] = '?';
		}
	}

	cout << org_str;

	return 0;
}