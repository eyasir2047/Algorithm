#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int N = 1e3 + 10;
int res[N][N];
int pred[N][N];

void printPath(int x, int y){
    if(pred[x][y] == -1){
        cout << "NO path " << endl;
        return;
    }

    vector<int> path;
    path.push_back(y);

    while(x != y){
        y = pred[x][y];
        path.push_back(y);
    }

    reverse(path.begin(), path.end());
    
    for(int p:path){
        cout << p << " ";
    }
    cout << endl;
}

class Graph
{
public:
    int V;
    vector<pair<int, int>> *adj;
    int *dist;

    Graph(int V)
    {
        this->V = V;
        adj = new vector<pair<int, int>>[V + 1];
        dist = new int[V + 1];

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                pred[i][j] = -1;

                if(i != j){
                    res[i][j] = INF;
                }else{
                    res[i][j] = 0;
                }
            }
        }
    }

    void addEgde(int x, int y, int wt)
    {
        adj[x].push_back({y, wt});
        pred[x][y] = x;
    }

    void Johnson(void)
    {
        // adding dummy edge
        for (int i = 0; i < V; i++)
        {
            // weight = 0;
            addEgde(V, i, 0);
            dist[i] = INF;
        }
        dist[V] = 0;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j <= V; j++)
            {
                for (auto e : adj[i])
                {
                    int src = i;
                    int dest = e.first;
                    int wt = e.second;

                    if (dist[dest] > dist[src] + wt and dist[src] != INF)
                    {
                        dist[dest] = dist[src] + wt;
                    }
                }
            }
        }

        // check for negative cycle
        for (int i = 0; i < V; i++)
        {
            for (auto e : adj[i])
            {
                int src = i;
                int dest = e.first;
                int wt = e.second;

                if (dist[dest] > dist[src] + wt and dist[src] != INF)
                {
                    cout << "Negative Cycle" << endl;
                    return;
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            for (auto &e : adj[i])
            {
                int src = i;
                int dest = e.first;
                int wt = e.second;

                e.second = wt + dist[i] - dist[dest];
            }
        }

        // Djisktra Algo
        bool vis[V];

        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                dist[i] = INF;
                vis[i] = false;
            }

            set<pair<int, int>> st;
            st.insert({0, k});
            dist[k] = 0;

            while (st.size() > 0)
            {
                int u = (*st.begin()).second;

                st.erase(st.begin());

                if (vis[u])
                {
                    continue;
                }
                vis[u] = true;

                for (auto child : adj[u])
                {
                    int v = child.first;
                    int wt = child.second;

                    if (dist[v] > dist[u] + wt)
                    {
                        dist[v] = dist[u] + wt;
                        st.insert({dist[v], v});
                        pred[k][v] = u;
                    }
                }
            }

            for (int i = 0; i < V; i++)
            {
                res[k][i] = dist[i];
            }
        }
    }

    void print(void)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (res[i][j] == INF)
                {
                    cout << " I ";
                    // printf("%5c", 'I');
                }
                else
                {
                    // printf("%5.d", res[i][j]);
                    cout << " " << res[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g = Graph(10);

    g.addEgde(0, 2, 1);
    g.addEgde(0, 1, 2);
    g.addEgde(2, 1, 2);
    g.addEgde(1, 3, 3);

    g.Johnson();
    printPath(1,0);

    return 0;
}