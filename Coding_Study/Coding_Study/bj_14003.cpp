#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1000001];
vector<int> ans;

int Binary_Search(int target)
{
	int left = 0;
	int right = ans.size() - 1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (target <= ans[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	ans.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (ans[ans.size() - 1] < arr[i]) ans.push_back(arr[i]);
		else
		{
			ans[Binary_Search(arr[i])] = arr[i];
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}