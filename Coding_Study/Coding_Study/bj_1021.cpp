/*
* 백준 1021 - 회전하는 큐
* 20240815
*/
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	int input, count = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		int j;
		for (j = 0; j < dq.size(); j++)
		{
			if (input == dq[j]) break;
		}

		if (j == 0) dq.pop_front();
		else if (j < dq.size() - j)
		{
			for (int k = 0; k < j; k++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			dq.pop_front();
		}
		else
		{
			for (int k = 0; k < dq.size() - j; k++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
			dq.pop_front();
		}
	}

	cout << count;

	return 0;
}