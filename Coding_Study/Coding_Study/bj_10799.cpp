/*
* 백준 10799 - 쇠막대기
* 20240815
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	getline(cin, str);

	int object = 0, sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' && str[i + 1] == ')')
		{
			sum += object;
			i++;
		}
		else
		{
			if (str[i] == '(')
			{
				object++;
				sum++;
			}
			else
			{
				object--;
			}
		}
	}

	cout << sum;

	return 0;
}