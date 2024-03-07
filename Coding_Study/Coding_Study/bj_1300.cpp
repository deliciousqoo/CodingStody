/*
* 백준1300 K번째 수
* 이분탐색
* 20240306
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, k;
	cin >> N >> k;

	long long start = 1, end = k, mid, cnt, ans;
	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;
		
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}

		if (cnt < k) {
			start = mid + 1;
		}
		else {
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans;

	return 0;
}