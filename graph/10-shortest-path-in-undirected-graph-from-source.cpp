#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> shortestPath(int V, vector<vector<int>> &graph, int src)
{
    vector<int> dist(V, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : graph[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> graph{
        {1, 3},
        {0, 2, 3},
        {1, 6},
        {0, 4},
        {3, 5},
        {4, 6},
        {2, 5, 7, 8},
        {6, 8},
        {6, 7}};
    vector<int> ans = shortestPath(9, graph, 0);

    for (int dist : ans)
        cout << dist << " ";
    cout << "\n";
    return 0;
}
