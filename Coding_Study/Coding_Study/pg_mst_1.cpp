/*
* 프로그래머스 섬 연결하기
* MST
* 20240521
*/
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int answer = 0;
    int n = 4;
    vector<vector<int>> costs = { {0, 1, 1},{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8 }};

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < costs.size(); i++)
    {
        graph[costs[i][0]][costs[i][1]] = costs[i][2];
        graph[costs[i][1]][costs[i][0]] = costs[i][2];
    }

    vector<int> visited;
    vector<int> unvisited;

    visited.push_back(0);
    for (int i = 1; i < n; i++)
    {
        unvisited.push_back(i);
    }

    for (int i = 1; i < n; i++)
    {
        int min = INT_MAX;
        int min_index = 0;

        for (int j = 0; j < visited.size(); j++)
        {
            for (int k = 0; k < unvisited.size(); k++)
            {
                if (graph[visited[j]][unvisited[k]] > 0 && graph[visited[j]][unvisited[k]] < min)
                {
                    min = graph[visited[j]][unvisited[k]];
                    min_index = k;
                }
            }
        }

        visited.push_back(unvisited[min_index]);
        unvisited.erase(unvisited.begin() + min_index);
        answer += min;
    }

    return answer;
}