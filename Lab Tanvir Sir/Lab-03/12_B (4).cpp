#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> adj[N];
int dt[N], low[N], parent[N], timeStamp;

stack<int> st;
vector<vector<int>> components;

void dfs(int u) {
  dt[u] = low[u] = ++timeStamp;
  st.push(u);


  for (int v : adj[u]) {
    if (dt[v] == 0) {
      parent[v] = u;
      dfs(v);

      low[u] = min(low[u], low[v]);
      if (low[v] >= dt[u]) {
        vector<int> component;
        int w;
        do {
          w = st.top();
          st.pop();
          component.push_back(w);
        } while (w != v);
        component.push_back(u);
        components.push_back(component);
      }

    } 
    else if (v != parent[u]) {
      low[u] = min(low[u], dt[v]);
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (dt[i] == 0) {
      dfs(i);
    }
  }

  sort(components.begin(), components.end(), [](const vector<int>& p, const vector<int>& q) {
    return p.front() < q.front();
  });


    int count = 0;
    int kk = components.size();

    for (const auto& it : components) {
      count++;
    
             vector<pair<int, int>> edges;
             for (int v : it) {
      
                 for (int u : adj[v]) {
                      if (find(it.begin(), it.end(), u) != it.end()) {
                     edges.push_back({min(u, v), max(u, v)});
         
         }
      }
      
    }
    
    sort( edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

     if( edges.empty() ){
        cout << "-" << endl;
    }



          else{
        for (const auto& edge : edges) {
       
            cout << edge.first << " " << edge.second << endl;
        }
      
        if( count != kk) cout << "-" << endl;
    }
    
   
    
  }

  return 0;
}