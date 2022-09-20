#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detectCycle(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1});
            visited[i] = true;
            while (!q.empty())
            {
                int node = q.front().first, par = q.front().second;
                q.pop();
                for (auto it : graph[node])
                {
                    if (it != par && visited[it])
                        return true;
                    if (!visited[it])
                    {
                        q.push({it, node});
                        visited[it] = true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> graph{
        {1},
        {0, 3},
        {4},
        {1},
        {2, 5, 9},
        {4, 6},
        {5, 7},
        {6, 8},
        {7, 9},
        {4, 8},
        {7}};

    cout << detectCycle(graph);
    return 0;
}
