/*
* ����14215 �� ����
* ����: ���簢���� �ﰢ��
* 20240226
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int A, B, C;
	vector<int> arr;

	cin >> A >> B >> C;

	arr.push_back(A);
	arr.push_back(B);
	arr.push_back(C);

	sort(arr.begin(), arr.end(), greater<>());

	while (arr[0] >= arr[1] + arr[2]) {
		arr[0]--;
	}

	cout << arr[0] + arr[1] + arr[2];

	return  0;
}