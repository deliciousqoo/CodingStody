/*
* 백준 2504 - 괄호의 값
* 20240815
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	getline(cin, str);

	stack<char> s;
	
	int sum = 0, temp = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			s.push('(');
			temp *= 2;
		}
		else if (str[i] == ')')
		{
			if (s.size() == 0)
			{
				sum = 0;
				break;
			}
			else if (str[i - 1] == '(')
			{
				sum += temp;
				temp /= 2;
			}
			else
			{
				temp /= 2;
			}

			if (s.top() == '(') s.pop();
		}
		else if (str[i] == '[')
		{
			s.push('[');
			temp *= 3;
		}
		else if (str[i] == ']')
		{
			if (s.size() == 0)
			{
				sum = 0;
				break;
			}
			else if (str[i - 1] == '[')
			{
				sum += temp;
				temp /= 3;
			}
			else
			{
				temp /= 3;
			}

			if (s.top() == '[') s.pop();
		}
	}

	if (s.size() != 0) sum = 0;

	cout << sum;

	return 0;
}