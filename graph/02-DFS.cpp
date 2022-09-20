#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<int> &dfs, vector<bool> &visited, vector<vector<int>> &graph)
{
    visited[node] = true;
    dfs.push_back(node);
    for (auto it : graph[node])
    {
        if (!visited[it])
            DFS(it, dfs, visited, graph);
    }
}

int main()
{
    vector<vector<int>> graph{
        {1},
        {0, 2, 6},
        {1, 4},
        {5},
        {2, 6},
        {3},
        {1, 4}};

    int n = graph.size();
    vector<int> dfs;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i, dfs, visited, graph);
        }
    }

    for (auto it : dfs)
        cout << it << " ";

    return 0;
}
