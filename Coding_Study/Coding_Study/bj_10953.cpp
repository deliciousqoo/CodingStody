/*
* 백준9251
* 문자열
* 20240519
*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	string temp;
	for (int i = 0; i < T; i++)
	{
		cin >> temp;
		istringstream ss(temp);
		string stringBuffer;

		int ans = 0;
		while (getline(ss, stringBuffer, ','))
		{
			ans += stoi(stringBuffer);
		}

		cout << ans << '\n';
	}

	return 0;
}