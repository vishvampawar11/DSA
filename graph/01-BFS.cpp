#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> BFS(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> bfs;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.emplace(i);
            visited[i] = true;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : graph[node])
                {
                    if (!visited[it])
                    {
                        q.emplace(it);
                        visited[it] = true;
                    }
                }
            }
        }
    }
    return bfs;
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
    vector<int> BFSTraversal = BFS(graph);

    for (auto it : BFSTraversal)
        cout << it << " ";
    return 0;
}
