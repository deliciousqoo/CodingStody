/*
* น้มุ
* 20240815
*/
#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<p> s;

	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		while (true)
		{
			if (s.size() == 0)
			{
				s.push(make_pair(i + 1, input));
				cout << 0 << " ";
				break;
			}

			if (s.top().second < input)
			{
				s.pop();
			}
			else
			{
				cout << s.top().first << " ";
				s.push(make_pair((i + 1), input));
				break;
			}
		}
	}

	return 0;
}