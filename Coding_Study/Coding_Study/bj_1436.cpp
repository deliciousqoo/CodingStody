/*
* ����1436 ��ȭ���� ��
* �θ�Ʈ ����
* 20240229
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool count_six(int num) {
	string temp = to_string(num);
	if (temp.find("666") != string::npos) {
		return true;
	}
	else return false;
}

int main() {

	int N;
	cin >> N;

	vector<int> arr;
	int count = 666;
	while (arr.size() < N) {
		if (count_six(count)) {
			arr.push_back(count);
		}
		count++;
	}

	cout << count - 1;

	return 0;
}

