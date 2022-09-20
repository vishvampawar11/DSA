#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, stack<int> &st)
{
    vis[node] = true;
    for (auto it : graph[node])
    {
        if (!vis[it])
            dfs(it, graph, vis, st);
    }
    st.push(node);
}

void topoSort(int V, vector<vector<int>> &graph)
{
    vector<bool> vis(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, graph, vis, st);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

int main()
{
    vector<vector<int>> graph{
        {1},
        {2},
        {0}};

    topoSort(3, graph);
    return 0;
}
