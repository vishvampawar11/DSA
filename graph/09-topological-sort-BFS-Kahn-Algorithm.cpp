#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topoSort(int V, vector<vector<int>> &graph)
{
    vector<int> indegree(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        for (auto it : graph[i])
            indegree[it]++;
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : graph[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    cout << "\n";
}

int main()
{
    vector<vector<int>> graph{
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2},
    };

    topoSort(6, graph);
    return 0;
}
