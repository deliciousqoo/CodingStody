/*
* ����10988 �Ӹ�������� Ȯ���ϱ�
* ��ȭ 1
* 20240220
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	string input;
	cin >> input;

	string temp = input;
	reverse(temp.begin(), temp.end());

	if (input == temp) cout << 1;
	else cout << 0;

	return 0;
}