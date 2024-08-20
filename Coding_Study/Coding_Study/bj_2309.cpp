/*
* πÈ¡ÿ 2309 - ¿œ∞ˆ ≥≠¿Ô¿Ã
* 20240815
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> arr(9);

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int i, j, sum;
	bool check = false;
	for (i = 0; i < 8 && !check; i++)
	{
		for (j = i + 1; j < 9 && !check; j++)
		{
			sum = 0;
			for (int k = 0; k < 9; k++)
			{
				if (k != i && k != j) sum += arr[k];
			}

			if (sum == 100)
			{
				check = true;
			}
		}
	}

	for (int k = 0; k < 9; k++)
	{
		if (k != i-1 && k != j-1) cout << arr[k] << endl;
	}

	return 0;
}