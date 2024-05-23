/*
* 백준1032
* 문자열
* 20240519
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> chess;
	
	chess.resize(8);
	for (int i = 0; i < 8; i++)
	{
		cin >> chess[i];
	}
	
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
			{
				if (chess[i][j] == 'F') count++;
			}
		}
	}

	cout << count;

	return 0;
}