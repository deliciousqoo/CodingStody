#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> graph;
//vector<bool> visited;
vector<bool> visited;
int sheep_count = 1;
int wolf_count = 0;

void BFS(int start, vector<int> info)
{
    queue<pair<int, int>> myqueue;
    myqueue.push(make_pair(start, 0));

    while (!myqueue.empty())
    {
        int now = myqueue.front().first;
        int wolf = myqueue.front().second;
        myqueue.pop();

        for (int i : graph[now])
        {
            if (info[i] == 0)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    sheep_count++;
                    wolf_count = wolf;
                    return;
                }
                else
                {
                    myqueue.push(make_pair(i, wolf));
                }
            }
            else if (info[i] == 1)
            {
                if (!visited[i])
                {
                    if (wolf + 1 < sheep_count)
                    {
                        myqueue.push(make_pair(i, wolf + 1));
                        visited[i] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    int answer = 0;
    vector<int> info = { 0,1,0,1,1,0,1,0,0,1,0 };
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 3},{1, 4},{2, 5},{2, 6},{3, 7},{4, 8},{6, 9},{9, 10},{8, 9} };

    graph.resize(info.size());
    visited.resize(info.size());

    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    int sheep_amount = 0;
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i] == 1) sheep_amount++;
    }

    for (int i = 0; i < sheep_amount; i++)
    {
        BFS(0, info);
    }

    answer = sheep_count;

    return answer;
}