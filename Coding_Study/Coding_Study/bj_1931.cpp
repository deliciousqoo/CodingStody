/*
* 백준1931
* 정렬
* 20240521
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> p;
vector<p> arr;

bool cmp(p p1, p p2)
{
	if (p1.second < p2.second) return true;
	else if (p1.second > p2.second) return false;
	else
	{
		if (p1.second - p1.first > p2.second - p2.first) return true;
		else return false;
	}
}

int main()
{
	int N;
	cin >> N;

	long long a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end(), cmp);

	long long end_point = 0, count = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].first >= end_point)
		{
			end_point = arr[i].second;
			count++;
		}
	}

	cout << count;

	return 0;
}