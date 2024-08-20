/*
* 백준11659
* 구간합
* 20240229
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	arr.resize(N);
	result.resize(N);

	for (int i = 0; i < N; i++) cin >> arr[i];

	result[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		result[i] = result[i - 1] + arr[i];
	}

	int left, right;
	for (int i = 0; i < M; i++)
	{
		cin >> left >> right;
		cout << result[right-1] - result[left-1] + arr[left-1] << "\n";
	}

	return 0;
}