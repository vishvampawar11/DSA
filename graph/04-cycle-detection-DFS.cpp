#include <iostream>
#include <vector>

using namespace std;

bool helper(int node, int par, vector<bool> &visited, vector<vector<int>> &graph)
{
    visited[node] = true;
    for (auto it : graph[node])
    {
        if (!visited[it])
        {
            if (helper(it, node, visited, graph))
                return true;
        }
        else if (it != par)
            return true;
    }
    return false;
}

bool detectCycle(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (helper(i, -1, visited, graph))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> graph{
        {1},
        {2},
        {0}};

    cout << detectCycle(graph);
    return 0;
}
