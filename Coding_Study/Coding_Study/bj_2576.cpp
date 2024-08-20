/*
* น้มุ 2576 - ศฆผ๖
* 20240815
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int min_value = 100;

	int input, sum = 0;
	for (int i = 0; i < 7; i++)
	{
		cin >> input;
		if (input % 2 == 1)
		{
			sum += input;
			min_value = min(input, min_value);
		}
	}

	if (sum == 0) cout << -1;
	else
	{
		cout << sum << '\n' << min_value;
	}

	return 0;
}