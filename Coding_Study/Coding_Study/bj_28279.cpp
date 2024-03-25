/*
* πÈ¡ÿ28279 µ¶ 2
* Ω∫≈√, ≈•, µ¶
* 20240325
*/
#include <iostream>
#include <deque>

using namespace std;
deque<int> myDeque;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		switch (input) {
			case 1:
				cin >> input;
				myDeque.push_front(input);
				break;
			case 2:
				cin >> input;
				myDeque.push_back(input);
				break;
			case 3:
				if (!myDeque.empty()) {
					cout << myDeque.front() << "\n";
					myDeque.pop_front();
				}
				else
				{
					cout << -1 << "\n";
				}
				break;
			case 4:
				if (!myDeque.empty()) {
					cout << myDeque.back() << "\n";
					myDeque.pop_back();
				}
				else
				{
					cout << -1 << "\n";
				}
				break;
			case 5:
				cout << myDeque.size() << "\n";
				break;
			case 6:
				if (myDeque.empty()) cout << "1\n";
				else cout << "0\n";
				break;
			case 7:
				if (myDeque.empty()) cout << "-1\n";
				else cout << myDeque.front() << "\n";
				break;
			case 8:
				if (myDeque.empty()) cout << "-1\n";
				else cout << myDeque.back() << "\n";
				break;
		}
	}

	return 0;
}