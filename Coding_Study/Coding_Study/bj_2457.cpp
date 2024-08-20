/*
* น้มุ
* 20240817
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, pair<int, int>> p;
vector<p> arr;
vector<bool> visited;
bool check = false;
bool end_check = false;
int cnt = 0;

bool compare(p p1, p p2)
{
	if (p1.second.first < p2.second.first) return true;
	else if (p1.second.first == p2.second.first)
	{
		if (p1.second.second < p2.second.second) return true;
		else return false;
	}
	else return false;
}

bool contain_check(int m, int d, p cur)
{
	bool check = true;

	if (cur.first.first > m || cur.second.first < m) check = false;
	else if (cur.first.first == m)
	{
		if (cur.first.second > d) check = false;
	}
	else if (cur.second.first == m)
	{
		if (cur.second.second < d) check = false;
	}

	return check;
}

void flower_count(int m, int d)
{
	if (end_check) return;
	if (check) return;

	int last_m = 0, last_d = 0, temp;
	for (int i = 0; i < arr.size(); i++)
	{
		if (contain_check(m, d, arr[i]))
		{
			if (!visited[i])
			{
				temp = i;
				last_m = arr[i].second.first;
				last_d = arr[i].second.second;
			}
		}
	}

	if (last_m != 0 && last_d != 0)
	{
		visited[temp] = true;
		cnt++;
		if (last_m >= 12) end_check = true;
		flower_count(last_m, last_d);
	}
	else check = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	arr.resize(N);
	visited.resize(N, false);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
	}

	sort(arr.begin(), arr.end(), compare);

	flower_count(3, 1);

	if (check) cout << 0;
	else
	{
		cout << cnt;
	}

	return 0;
}