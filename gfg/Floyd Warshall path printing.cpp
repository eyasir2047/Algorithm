#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
const int N = 1e3+10;

// #define infinity INT_MAX;

void PrintShortestPath(vector<vector<int>> &predecessor, int src, int dest)
{

    if (predecessor[src][dest] == -1)
    {
        cout << "no path exists" << endl;
        return;
    }

    int i = src, j = dest;
    vector<int> path;

    path.push_back(j);

    while (i != j)
    {
        j = predecessor[i][j];
        path.push_back(j);
    }

    reverse(path.begin(), path.end());
    for (int a : path)
    {
        cout << a << " ";
    }

    cout << endl;
}

vector<vector<int>> Floyd_Warshall(vector<vector<pair<int, int>>> graph, int v)
{

    vector<vector<int>> dp(v, vector<int>(v));

    vector<vector<int>> predecessor(v, vector<int>(v));

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i != j)
            {
                dp[i][j] = INT_MAX;
            }
            else
            {
                dp[i][j] = 0;
            }

            predecessor[i][j] = -1;
        }
    }

    for (int i = 0; i < graph.size(); i++)
    {

        for (auto &a : graph[i])
        {
            int j = a.first;
            int w = a.second;

            // cout<<j<<endl;

            dp[i][j] = w;
            predecessor[i][j] = i;
        }
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {

                if ((dp[i][k] != INT_MAX) and (dp[k][j] != INT_MAX))
                {

                    if (dp[i][j] > dp[i][k] + dp[k][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        if (predecessor[i][k] != -1)
                            predecessor[i][j] = predecessor[k][j];
                    }
                }
            }
        }
    }

    PrintShortestPath(predecessor, 0, 3);
    PrintShortestPath(predecessor, 0, 2);

    return dp;
}

int main()
{

    int v, e;

    cin >> v >> e;

    vector<vector<pair<int, int>>> graph(v);

    while (e--)
    {
        int x, y, w;

        cin >> x >> y >> w;

        graph[x].push_back({y, w});
    }

    vector<vector<int>> ans = Floyd_Warshall(graph, v); // works for both directed and undirected graph

    /*
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

    */
    return 0;
}