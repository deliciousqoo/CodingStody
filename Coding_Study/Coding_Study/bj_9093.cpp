/*
* 백준2754
* 문자열
* 20240519
*/
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	string temp;
	for (int i = 0; i <= T; i++)
	{
		getline(cin, temp);
		istringstream ss(temp);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' '))
		{
			reverse(stringBuffer.begin(), stringBuffer.end());
			cout << stringBuffer << " ";
		}
	}

	return 0;
}