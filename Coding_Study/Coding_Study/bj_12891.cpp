/*
* 백준12891
* 슬라이딩 윈도우
* 20240702
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> dna_check;
vector<int> current_check;
vector<char> dna;

int dna_index(char input)
{
	switch (input)
	{
		case 'A':
			return 0;
			break;
		case 'C':
			return 1;
			break;
		case 'G':
			return 2;
			break;
		case 'T':
			return 3;
			break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;
	cin >> S >> P;

	dna.resize(S);
	dna_check.resize(4);
	current_check.resize(4);

	for (int i = 0; i < S; i++)
	{
		cin >> dna[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> dna_check[i];
	}

	for (int i = 0; i < P; i++)
	{
		current_check[dna_index(dna[i])]++;
	}

	int left = 0, right = P - 1, count = 0, temp;
	while (1)
	{
		temp = 0;
		for (int i = 0; i < 4; i++)
		{
			if (current_check[i] >= dna_check[i]) temp++;
		}
		if (temp == 4) count++;
		if (right == S-1) break;

		current_check[dna_index(dna[left++])]--;
		current_check[dna_index(dna[++right])]++;
	}

	cout << count;

	return 0;
}