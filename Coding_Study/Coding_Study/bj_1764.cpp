/*
* 백준1764
* 문자열
* 20240519
*/
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, count = 0;
	cin >> N >> M;

	map<string, int> m;
	map<string, int>::iterator iter;

	string temp;
	for (int i = 0; i < N+M; i++)
	{
		cin >> temp;
		m[temp]++;
		if (m[temp] == 2) count++;
	}
	
	cout << count << '\n';
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (iter->second == 2) cout << iter->first << '\n';
	}

	return 0;
}