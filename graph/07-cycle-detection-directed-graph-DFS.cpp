#include <iostream>
#include <vector>

using namespace std;

bool cycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis)
{
    vis[node] = true;
    dfsVis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (cycle(it, adj, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
        {
            return true;
        }
    }
    dfsVis[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> vis(V, false), dfsVis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (cycle(i, adj, vis, dfsVis))
            {
                return true;
            }
    }
    return false;
}

int main()
{
    vector<int> graph[] = {
        {1, 2},
        {2, 3},
        {3},
        {3}};

    cout << isCyclic(4, graph);
    return 0;
}
