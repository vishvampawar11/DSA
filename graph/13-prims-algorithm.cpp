#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void prim(int n, vector<vector<pair<int, int>>> &adj)
{
    vector<int> cost(n, 1e8), mst(n, 0), par(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cost[0] = 0;
    pq.push({0, 0});

    for (int i = 0; i < n - 1; i++)
    {
        int u = pq.top().second;
        pq.pop();
        mst[u] = 1;

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if (mst[v] == 0 && wt < cost[v])
            {
                par[v] = u;
                pq.push({cost[v], v});
                cost[v] = wt;
            }
        }
    }
    int totalCost = 0;
    for (int i = 1; i < n; i++)
    {
        totalCost += cost[i];
        cout << par[i] << " - " << i << "\n";
    }
    cout << "Cost = " << totalCost << "\n";
}

int main()
{
    vector<vector<pair<int, int>>> adj{
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {4, 5}, {3, 8}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}},
        {{1, 5}, {2, 7}}};

    prim(5, adj);

    return 0;
}
