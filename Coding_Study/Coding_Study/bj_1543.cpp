/*
* น้มุ
* 20240816
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, find_str;
	getline(cin, str);
	getline(cin, find_str);

	int cnt = 0;
	while (true)
	{
		if (str.find(find_str) == string::npos) break;

		cnt++;

		str = str.substr(str.find(find_str) + find_str.length());
	}

	cout << cnt;

	return 0;
}