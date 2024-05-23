/*
* 백준2754
* 문자열
* 20240519
*/
#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	float ans = 0;
	if (s[0] == 'A') ans += 4;
	else if (s[0] == 'B') ans += 3;
	else if (s[0] == 'C') ans += 2;
	else if (s[0] == 'D') ans += 1;

	if (s[0] != 'F')
	{
		if (s[1] == '+') ans += 0.3;
		else if (s[1] == '-') ans -= 0.3;
	}

	printf("%.1f", ans);

	return 0;
}