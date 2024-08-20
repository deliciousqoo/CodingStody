/*
* น้มุ 1074 - Z
* 20240816
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<int, int> p;
int N, r, c;
int cnt = 0;
bool check;

void find_z(p s, p e)
{
	if (check) return;
	if (r > e.first || r < s.first || c > e.second || c < s.second)
	{
		cnt += (e.first - s.first + 1) * (e.second - s.second + 1);
		return;
	}

	if (s == e)
	{
		if (s.first == r && s.second == c)
		{
			cout << cnt;
			check = true;
		}
		cnt++;
		return;
	}


	find_z(s, make_pair(s.first + (e.first-s.first)/2, s.second + (e.second-s.second)/2));
	find_z(make_pair(s.first, s.second + (e.second - s.second) / 2 + 1), make_pair(s.first + (e.first-s.first)/2, e.second));
	find_z(make_pair(s.first + (e.first - s.first) / 2 + 1, s.second), make_pair(e.first, s.second + (e.second - s.second) / 2));
	find_z(make_pair(s.first + (e.first - s.first) / 2 + 1, s.second + (e.second - s.second) / 2 + 1), e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	find_z(make_pair(0, 0), make_pair(pow(2, N)-1, pow(2, N)-1));

	return 0;
}