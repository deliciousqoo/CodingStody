/*
* ����2747 �Ǻ���ġ ��
* ������ȹ��
* 20240311
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

/*
* ���Ҿ� ���
int main() {

	int n;
	cin >> n;

	arr.push_back(0);
	arr.push_back(1);

	int temp;
	for (int i = 2; i <= n; i++) {
		temp = arr[i - 1] + arr[i - 2];
		arr.push_back(temp);
	}

	cout << arr[n];

	return 0;
}*/

/*
* ��ٿ� ���
int fibo(int num) {
	if (arr[num] != -1) return arr[num];
	return arr[num] = fibo(num - 1) + fibo(num - 2);
}

int main() {

	int n;
	cin >> n;
	
	arr.resize(n + 1, -1);
	arr[0] = 0;
	arr[1] = 1;
	
	cout << fibo(n);

	return 0;
}*/