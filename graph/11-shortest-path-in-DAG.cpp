#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<pair<int, int>>> &graph, vector<bool> &vis, stack<int> &st)
{
    vis[node] = true;
    for (auto it : graph[node])
    {
        if (!vis[it.first])
            dfs(it.first, graph, vis, st);
    }
    st.push(node);
}

void shortestPath(int V, int src, vector<vector<pair<int, int>>> &graph)
{
    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, graph, vis, st);
    }
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX)
        {
            for (auto it : graph[node])
                dist[it.first] = min(dist[node] + it.second, dist[it.first]);
        }
    }
    for (int d : dist)
        cout << d << " ";
    cout << "\n";
}

int main()
{
    vector<vector<pair<int, int>>> graph{
        {{1, 2}, {4, 1}},
        {{2, 3}},
        {{3, 6}},
        {},
        {{2, 2}, {5, 4}},
        {{3, 1}}};

    shortestPath(6, 0, graph);
    return 0;
}
