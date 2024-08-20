/*
* 백준11003
* 슬라이딩 윈도우
* 20240702
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
vector<int> arr;
deque<pair<int, int>> min_values;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;

	arr.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	
	int left = 0, right = 0;
	while (right < N)
	{
		if (min_values.size() == 0)
		{
			min_values.push_back(make_pair(right, arr[right]));
		}
		else
		{
			if (min_values.front().first == left-1) min_values.pop_front();
			
			while (true)
			{
				if (min_values.size() == 0) break;
				if (min_values.back().second > arr[right]) min_values.pop_back();
				else break;
			}
			min_values.push_back(make_pair(right, arr[right]));
		}

		right++;
		left = max(0, right - L + 1);
		cout << min_values.front().second << " ";
	}

	return 0;
}