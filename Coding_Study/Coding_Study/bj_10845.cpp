/*
* น้มุ 10866 - ตฆ
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

	int N;
	cin >> N;

	deque<int> dq;

	string command;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "front")
		{
			if (dq.size() == 0) cout << -1 << endl;
			else cout << dq.front() << endl;
		}
		else if (command == "back")
		{
			if (dq.size() == 0) cout << -1 << endl;
			else cout << dq.back() << endl;
		}
		else if (command == "size")
		{
			cout << dq.size() << endl;
		}
		else if (command == "empty")
		{
			if (dq.size() == 0) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (command == "pop_front")
		{
			if (dq.size() == 0) cout << -1 << endl;
			else
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (command == "pop_back")
		{
			if (dq.size() == 0) cout << -1 << endl;
			else
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
	}

	return 0;
}