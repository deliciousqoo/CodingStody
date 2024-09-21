#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<int> beadsSum;
string M;
int N, Q;

void initializeBeadsSum()
{
    long long temp_sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (M[i] == '*')
        {
            beadsSum[i] = temp_sum;
        }
        else
        {
            temp_sum += M[i] - '0';
        }
    }
}

bool checkSameArea(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (M[i] == '*') return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;
    cin >> Q;

    beadsSum.resize(N, 0);

    initializeBeadsSum();

    while (Q--)
    {
        int S, E;
        cin >> S >> E;

        if (!checkSameArea(S, E))
        {
            cout << 0 << "\n";
        }
        else
        {
            while (M[S] != '*') S++;
            while (M[E] != '*') E--;

            cout << beadsSum[E] - beadsSum[S] << "\n";
        }
    }

    return 0;
}