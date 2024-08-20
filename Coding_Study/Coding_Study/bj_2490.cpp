/*
* πÈ¡ÿ 2490 - ¿∑≥Ó¿Ã
* 20240815
*/
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0, temp;

	for (int i = 0; i < 3; i++)
	{
		count = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> temp;
			if (temp == 1) count++;
		}

		switch (count)
		{
			case 0:
				cout << 'D';
				break;
			case 1:
				cout << 'C';
				break;
			case 2:
				cout << 'B';
				break;
			case 3:
				cout << 'A';
				break;
			case 4:
				cout << 'E';
				break;
		}
		cout << endl;
	}

	return 0;
}
