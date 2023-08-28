#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

vector<int> graph[N];
bool visited[N];
int dt[N];
int low[N];
vector<pair<int, int>> bridges;

void dfs(int node, int parent,int time) {
    visited[node] = true;
    dt[node] = low[node] = time++;

    for (int child : graph[node]) {
        if (child == parent) continue;

        if (!visited[child]) {
            dfs(child, node,time);
            low[node] = min(low[node], low[child]);
            if (low[child] > dt[node])
                bridges.push_back(make_pair(min(node, child), max(node, child)));
        } else {
            low[node] = min(low[node], dt[child]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1,0);
        }
    }

    sort(bridges.begin(), bridges.end());

    for (auto& bridge : bridges) {
        cout << bridge.first << " " << bridge.second << endl;
    }

    return 0;
}
