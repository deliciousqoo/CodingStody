/*
* ����3003 ŷ, ��, ��, ���, ����Ʈ, ��
* ��ȭ 1
* 20240220
*/
#include <iostream>

using namespace std;

int main() {

	int arr[6] = { 1, 1, 2, 2, 2, 8 };

	int temp;
	for (int i = 0; i < 6; i++) {
		cin >> temp;
		arr[i] -= temp;
		cout << arr[i] << " ";
	}

	return 0;
}