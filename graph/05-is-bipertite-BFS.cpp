#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipertite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> colored(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (colored[i] == -1)
        {
            colored[i] = 0;
            q.push(i);
            while (!q.empty())
            {
                int node = q.front(), color = colored[node];
                q.pop();
                for (auto it : graph[node])
                {
                    if (colored[it] == -1)
                    {
                        q.push(it);
                        colored[it] = color == 0 ? 1 : 0;
                    }
                    else
                    {
                        if (colored[it] == color)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph{
        {1},
        {0, 2, 7},
        {1, 3},
        {2, 4},
        {3, 5, 7},
        {4, 6},
        {5},
        {1, 4}};

    cout << isBipertite(graph);

    return 0;
}
