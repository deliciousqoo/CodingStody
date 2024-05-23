/*
* 백준5430
* 문자열
* 20240519
*/
#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	string p, temp;
	int n, start_pos;
	bool reverse_check, error_check;
	deque<int> dq;

	while (T-- > 0)
	{
		cin >> p;
		cin >> n;
		cin >> temp;

		reverse_check = false;
		error_check = false;
		dq.clear();

		istringstream ss(temp.substr(1, temp.size()-2));
		string stringBuffer;
		while (getline(ss, stringBuffer, ','))
		{
			dq.push_back(stoi(stringBuffer));
		}

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				if (reverse_check) reverse_check = false;
				else reverse_check = true;
			}
			else if (p[i] == 'D')
			{
				if (dq.size() == 0)
				{
					error_check = true;
					break;
				}
				else
				{
					if (reverse_check) dq.pop_back();
					else dq.pop_front();
				}
			}
		}

		if (error_check) cout << "error\n";
		else
		{
			cout << "[";
			if (dq.size() != 0)
			{
				
				if (!reverse_check)
				{
					for (int i = 0; i < dq.size(); i++)
					{
						cout << dq[i];
						if (i != dq.size() - 1) cout << ",";
					}
				}
				else
				{
					for (int i = dq.size() - 1; i >= 0; i--)
					{
						cout << dq[i];
						if (i != 0) cout << ",";
					}
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}