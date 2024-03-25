/*
* πÈ¡ÿ2346 «≥º± ≈Õ∂ﬂ∏Æ±‚
* Ω∫≈√, ≈•, µ¶
* 20240325
*/
#include <iostream>
#include <deque>
#include <math.h>

using namespace std;

typedef pair<int, int> p;
deque<p> myDeque;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		myDeque.push_back(make_pair(i, input));
	}

	int temp = 1, count = 1;
	while (!myDeque.empty()) {
		if (count == abs(temp)) {
			cout << myDeque.front().first << " ";
			temp = myDeque.front().second;
			myDeque.pop_front();
			if (temp < 0) count = 0;
			else count = 1;
		}
		else if(temp > 0)
		{
			myDeque.push_back(myDeque.front());
			myDeque.pop_front();
			count++;
		}
		else if (temp < 0) {
			myDeque.push_front(myDeque.back());
			myDeque.pop_back();
			count++;
		}
	}

	return 0;
}