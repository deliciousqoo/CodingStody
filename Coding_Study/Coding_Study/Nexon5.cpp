#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> str_arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> str_arr[i];
    }

    vector<string> temp;
    temp.push_back(str_arr[0]);
    for (int i = 1; i < N; i++)
    {
        bool check = false;
        for (int j = 0; j < temp.size(); j++)
        {
            if (str_arr[i].length() < temp[j].length()) continue;
            if (str_arr[i].find(temp[j]) != string::npos)
            {
                cout << str_arr[i] << "\n";
                check = true;
                break;
            }
        }

        if (!check) temp.push_back(str_arr[i]);
    }

    return 0;
}