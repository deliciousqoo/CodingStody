/*
* 백준9252 LCS 2
* 동적계획법
* 20240312
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

string s1, s2;
vector<vector<int>> D;
vector<char> ans;

void getText(int i, int j) {
	if (i == 0 || j == 0) return;

	if (s1[i-1] == s2[j-1]) {
		ans.push_back(s1[i-1]);
		getText(i - 1, j - 1);
	}
	else
	{
		if (D[i - 1][j] > D[i][j - 1]) {
			getText(i - 1, j);
		}
		else
		{
			getText(i, j - 1);
		}
	}
}

int main() {

	cin >> s1 >> s2;

	D.resize(s1.length()+1);
	for (int i = 0; i <= s1.length(); i++) {
		D[i].resize(s2.length()+1, 0);
	}

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				D[i][j] = D[i - 1][j - 1] + 1;
			}
			else
			{
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);
			}
		}
	}
	
	/*
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			cout << D[i][j] << " ";
		}
		cout << endl;
	}*/

	getText(s1.length(), s2.length());

	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}