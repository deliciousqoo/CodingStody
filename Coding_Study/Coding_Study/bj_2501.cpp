/*
* ����2501 ��� ���ϱ�
* ���, ����� �Ҽ�
* 20240226
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> arr;

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) arr.push_back(i);
	}
	if (K - 1 > arr.size() - 1) cout << 0;
	else cout << arr[K - 1];

	return 0;
}