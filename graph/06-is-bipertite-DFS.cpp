#include <iostream>
#include <vector>

using namespace std;

bool helper(int node, vector<int> &colored, vector<vector<int>> &graph)
{
    for (auto it : graph[node])
    {
        if (colored[it] == -1)
        {
            colored[it] = 1 - colored[node];
            if (helper(it, colored, graph))
                return true;
        }
        else if (colored[it] == colored[node])
            return false;
    }
    return false;
}

bool isBipertite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> colored(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (colored[i] == -1)
        {
            colored[i] = 1;
            if (helper(i, colored, graph))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> graph{
        {1},
        {0, 2, 7},
        {1, 3},
        {2, 4},
        {3, 5, 7},
        {4, 6},
        {5},
        {1, 4}};

    cout << isBipertite(graph);

    return 0;
}
