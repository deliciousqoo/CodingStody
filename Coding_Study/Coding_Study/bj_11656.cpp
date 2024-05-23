/*
* 백준11656
* 문자열
* 20240521
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	vector<string> s_arr;
	for (int i = 0; i < s.length(); i++)
	{
		//cout << s.substr(i) << "\n";
		s_arr.push_back(s.substr(i));
	}
	sort(s_arr.begin(), s_arr.end());

	for (int i = 0; i < s_arr.size(); i++)
	{
		cout << s_arr[i] << '\n';
	}

	return 0;
}