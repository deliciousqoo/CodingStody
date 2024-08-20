/*
* น้มุ
* 20240816
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A, B, ans;

bool binary_search(int target)
{
	int left = 0;
	int right = B.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (target < B[mid])
		{
			right = mid - 1;
		}
		else if (target > B[mid])
		{
			left = mid + 1;
		}
		else
		{
			return true;
		}
	}

	ans.push_back(target);

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nA, nB;
	cin >> nA >> nB;

	A.resize(nA);
	B.resize(nB);

	for (int i = 0; i < nA; i++) cin >> A[i];
	for (int i = 0; i < nB; i++) cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int cnt = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if(!binary_search(A[i])) cnt++;
	}

	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}