#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dice;
vector<int> current;
int m, n;
int ans = 0;

void calculateCombination(int target, int index)
{
	if (target == 0)
	{
		do
		{
			ans++;
		} while (next_permutation(current.begin(), current.end()));

		return;
	}

	for (int i = index; i < dice.size(); i++)
	{
		if (target - dice[i] >= 0)
		{
			current.push_back(dice[i]);
			calculateCombination(target - dice[i], i);
			current.pop_back();
		}
	}
}

int main()
{
	cin >> m >> n;

	dice.resize(m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> dice[i];
	}

	calculateCombination(n, 0);

	cout << ans;
}