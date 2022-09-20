#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int src, int n, vector<vector<pair<int, int>>> &adj)
{
    vector<int> distance(n, 1e8);
    distance[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    minh.push({0, src});

    while (!minh.empty())
    {
        int node = minh.top().second;
        int dist = minh.top().first;
        minh.pop();
        for (auto it : adj[node])
        {
            if (dist + it.second < distance[it.first])
            {
                distance[it.first] = dist + it.second;
                minh.push({distance[it.first], it.first});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << src << " => " << i << " = " << distance[i] << "\n";
}

int main()
{
    vector<vector<pair<int, int>>> adj{
        {{1, 2}, {3, 1}},
        {{0, 2}, {2, 4}, {4, 5}},
        {{1, 4}, {3, 3}, {4, 1}},
        {{0, 1}, {2, 3}},
        {{1, 5}, {2, 1}}};

    dijkstra(0, 5, adj);
    return 0;
}
