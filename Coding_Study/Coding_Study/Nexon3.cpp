#include <iostream>
#include <vector>
#include <string>

using namespace std;

char firstThird[8] = { 'b','d','g','n','p','r','s','t' };
char secondFourth[5] = { 'a','e','i','o','u' };
vector<string> allCases;
vector<bool> check;

vector<string> generateAllCases()
{
	vector<string> cases;
	for (char first : firstThird)
	{
		for (char second : secondFourth)
		{
			for (char third : firstThird)
			{
				if (third == first) continue;
				for (char fourth : secondFourth)
				{
					if (fourth == second) continue;
					string temp = "";
					temp += first;
					temp += second;
					temp += third;
					temp += fourth;
					cases.push_back(temp);
				}
			}
		}
	}

	return cases;
}

void calculateDinoName(string input, int strike, int ball)
{
	for (int i = 0; i < allCases.size(); i++)
	{
		if (!check[i]) continue;

		int temp_strike = 0;
		int temp_ball = 0;

		//check strike
		for (int j = 0; j < 4; j++)
		{
			if (input[j] == allCases[i][j]) temp_strike++;
		}
		if (strike != temp_strike)
		{
			check[i] = false;
			continue;
		}

		//check ball
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (input[j] == allCases[i][k] && j != k) temp_ball++;
			}
		}
		if (ball != temp_ball)
		{
			check[i] = false;
		}
	}
}

int main()
{
	allCases = generateAllCases();
	check.resize(allCases.size(), true);

	int n;
	cin >> n;

	string s;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> a >> b;
		calculateDinoName(s, a, b);
	}

	vector<string> ans;
	for (int i = 0; i < allCases.size(); i++)
	{
		if (check[i]) ans.push_back(allCases[i]);
	}

	if (ans.size() >= 2 || ans.size() == 0)
	{
		cout << 'x';
	}
	else
	{
		cout << ans[0];
	}

	return 0;
}