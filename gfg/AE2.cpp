#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define all(x) sort(x.begin(),x.end())
#define pb push_back
#define first f
#define second s
#define rep(i,a,b) for(ll i=a;i<b;i++)
const int N=1e5+10;
vector<int>g[N];
int visited[N];
int level[N];// shortest distance

int n,m;
vector<int>ans(n);

void bfs(int source){
    
        queue<int>q;
        q.push(source);
        visited[source]=1;
        
        while(!q.empty()){
            int curr=q.front();
           // cout<<curr<<" ";
           ans.push_back(curr);
            q.pop();
            for(auto child:g[curr]){
                if(!visited[child]){
                    
                q.push(child);
                visited[child]=1;
                level[child]=level[curr]+1;
                
                }
            }
        }
        
       // cout<<endl;
        
}

int main(){
    
    cin>>n>>m;
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    bfs(0);//bfs(starting node)
   
   for(int i=0;i<n;i++){
       cout<<ans[i]<<" ";
   }
   cout<<endl;
    
//    for(int i=1;i<=n;i++){
//        cout<<i<<":"<<level[i]<<endl;
//    }
    for(int i=0;i<n;i++){
        cout<<i<<":"<<level[i]<<endl;
      }
    
        
        
        return 0;
    
}































/*

lab-01 
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);
vector<int>g[N];
int n,m;

int main(){
            eyasir2047
         cin>>n>>m;
       
    for(int i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        //g[v].push_back(u);
       
}

for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto x : g[i]) {
            cout << x << " ";
        }
        cout << endl;
    }




            return 0;

}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);

int n,m;
	

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        int n=V;
         vector <bool> vis(n+1,false);
          int source=S;
          vector<int>dt(n+1,1e9+10);
          dt[source]=0;
     
    
     
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,source});
          
         while(!pq.empty()){
         
              int node=pq.top().second;
              int dist=pq.top().first;
              pq.pop();
              if(!vis[node]){
                  
              vis[node]=true;
            
              for(auto child:adj[node]){
                  int adjNode=child[0];//{u,{v,w}}-> child->{v,w}
                  int edgeW=child[1];
                  
                  if(dist+edgeW<dt[adjNode]){
                    
                      dt[adjNode]=dist+edgeW;
                      pq.push({dt[adjNode],adjNode});
                  }
              }
              }
          }
          vector<int>ans;
          
          
          for(int i=0;i<n;i++){
              if(dt[i]<1e9+10){
                 // cout<<dt[i]<<" ";
                 ans.push_back(dt[i]);
              }
              else{
                  ans.push_back(-1);
                 // cout<<"-1"<<" ";
                  }
          }
          
          return ans;
          
          
        
}

int main(){
     cin>>n>>m;
     vector<vector<int>>adj[n];
       
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
       adj[u].push_back({v,1});
       
}
    vector<int>ans=dijkstra(n,adj,0);
    for(int i=0;i<ans.size();i++){
        if(ans[i]!=-1)
        cout<<i<<": "<<ans[i]<<" "<<endl;
        else
        cout<<i<<": "<<"Not Reachable"<<endl;
    }
    cout<<endl;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

const int N = 1e5+10;
vector<int> g[N];

bool vis[N];

int dt[N];
int ft[N];
int num = 0;
int com[N];
int cnt=0;

void dfs(int node) {
    vis[node] = true;
    num++;
    dt[node] = num;
   
  priority_queue<int, vector<int>, greater<int>> pq;//minheap
  pq.push(node);
    com[node]=cnt;
    
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
    for (auto child : g[u]) {
        
        com[child]=cnt;
        if (!vis[child]) {
            dfs(child);
            pq.push(child);
        }
    }
    }

    ft[node] = ++num;
    
    
    }

int main() {
    
    eyasir2047
    int n, m;
    cin >> n >> m;
    

   
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); 
    }

   
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
        
       for (int i = 0; i < n; i++) {
        cout << i << ": "<<com[i]<<" "<<dt[i]<<" "<<ft[i]<<endl;
       
        
    }
    


   return 0;     
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;

bool dfs(vector<int>adj[],bool vis[],int node,int parent){
       vis[node]=1;
       
       for(auto child:adj[node]){
           if(!vis[child]){
               vis[child]=1;
               if(dfs(adj,vis,child,node))return true;
           }else if(child!=parent){//vis[child]==true
               return true;
           }
       }
       
       return false;
        
    }
bool isCycle(int V, vector<int> adj[]) {
       
        bool vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(dfs(adj,vis,i,-1))return true;
            }
        }
        return false;
    }
    
    int main(){
        
    cin>>n>>m;
    vector<int>g[n];
       
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
       
}
    if(!isCycle(n,g))
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;


}


lab-02

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
int vis[N];

int n,m;

stack<int>st;

void dfs(int node){
	    vis[node]=1;
	  
	    
	    for(auto child: adj[node]){
	        
	        if(!vis[child]){
	       
	            dfs(child);
	         
	           
	        }
	    }
	    //cout<<node<<" ";
	    st.push(node);
	}
	    
	    

int main(){
    
    cin>>n>>m;
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
      for(int i=0;i<n;i++){
	        if(!vis[i]){
	            dfs(i);
	        }
	    }
	    
	    vector<int>ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	   // cout<<endl;
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i]<<endl;
	    }
   // cout<<endl;
    
        
        
        return 0;
    
}


#include <bits/stdc++.h>
using namespace std;
static int cnt=0;

class Graph
{
	int V; 
	list<int> *adj;
	vector<int> indegree;
void ans(vector<int>& res,bool visited[]);

public:
	Graph(int V); 
	void addEdge(int v, int w);
	void sort();
};


Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	for (int i = 0; i < V; i++)
		indegree.push_back(0);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
	indegree[w]++;
}


void Graph::ans(vector<int>& res,bool visited[])
{
	
	bool flag = false;

	for (int i = 0; i < V; i++)
	{
		
		if (indegree[i] == 0 && !visited[i])
		{
		
			list<int>:: iterator j;
			for (j = adj[i].begin(); j != adj[i].end(); j++)
				indegree[*j]--;

			
			res.push_back(i);
			visited[i] = true;
			ans(res, visited);

			
			visited[i] = false;
			res.erase(res.end() - 1);
			for (j = adj[i].begin(); j != adj[i].end(); j++)
				indegree[*j]++;

			flag = true;
		}
	}

	
	if (!flag)
	{
		cnt++;
		
	}
}


void Graph::sort()
{
	
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	vector<int> res;
	ans(res, visited);
}


int main()
{
	int n,m;
	cin>>n>>m;

	Graph g(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	// int kk=1;
    //      for(auto i:l){
    //         if(i.second>1){
    //             //kk*=i.second;
    //             kk++;
    //         }
    //      }
        
    // cout<<kk<<endl;

    //    for(auto i:v){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl; 
    //    }
    //    int k=cnt; 
    //  for(auto i:mp){
    //         k*=i.second;
    //  }
    //  cout<<k<<endl;
    //  for(int i=0;i<n;i++){
    //      cout<<ans[i]<<" ";
    //  }

     //cout<<cnt<<endl;
    // cout<<endl;
	
	g.sort();
	cout<<cnt<<endl;

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void dfs(int curr,bool vis[],vector<int>adj[],int dt[],int low[],vector<bool>&ap,int time,int par){
      vis[curr]=1;
      time++;
      dt[curr]=low[curr]=time;
       int children=0;
      
      for(auto child:adj[curr]){
          if(par==child)continue;
          else if(!vis[child]){
               dfs(child,vis,adj,dt,low,ap,time,curr);
              low[curr]=min(low[curr],low[child]);
              if(par!=-1 && dt[curr]<=low[child]){
                  ap[curr]=1;
              }
              children++;
          }
          else{//vis[child]
               low[curr]=min(low[curr],dt[child]);
          }
      }
       if(par==-1 && children>1){
       ap[curr]=1;
      }
      
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int dt[V];
        int low[V];
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
        }
        int parent=-1;
        int time=0;
        vector<bool>ap(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,dt,low,ap,time,parent);
            }
        }
         vector<int>ans;
        for(int i=0;i<V;i++){
            if(ap[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0)return {-1};
        
        return ans;
    }
};


int main(){
	int tc;
	//cin >> tc;
    tc=1;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i <<endl;
		cout << "\n";
	}
	return 0;
}


      #include <bits/stdc++.h>
using namespace std;
 
int n, m, answer = 0;
char grid[1010][1010];
 
void  DFS (int i, int j) {
  if (i < 0) return;
  if (j < 0) return;
  if (i >= n) return ;
  if (j >= m) return;
  if (grid[i][j] == '#') return;
  
  grid[i][j]='#';
  
    DFS(i+1,j);
    DFS(i-1,j);
    DFS(i,j-1);
    DFS(i,j+1);
 
}
 
 
int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j];
      
      }
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == '.') {
            answer++;
          DFS(i, j);
          
        }
      }
    }
    cout << answer << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void dfs(int curr,bool vis[],vector<int>adj[],int dt[],int low[],vector<bool>&ap,int time,int par){
      vis[curr]=1;
      time++;
      dt[curr]=low[curr]=time;
       int children=0;
      
      for(auto child:adj[curr]){
          if(par==child)continue;
          else if(!vis[child]){
               dfs(child,vis,adj,dt,low,ap,time,curr);
              low[curr]=min(low[curr],low[child]);
              if(par!=-1 && dt[curr]<=low[child]){
                  ap[curr]=1;
              }
              children++;
          }
          else{//vis[child]
               low[curr]=min(low[curr],dt[child]);
          }
      }
       if(par==-1 && children>1){
       ap[curr]=1;
      }
      
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int dt[V];
        int low[V];
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
        }
        int parent=-1;
        int time=0;
        vector<bool>ap(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,dt,low,ap,time,parent);
            }
        }
         vector<int>ans;
        for(int i=0;i<V;i++){
            if(ap[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0)return {-1};
        
        return ans;
    }
};

int main(){
	int tc;
	//cin >> tc;
    tc=1;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		//for(auto i: ans)cout << i <<endl;
		//cout << "\n";
        cout<<V-ans.size()<<endl;
	}
	return 0;
}


      

lab-03

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


#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	
	int parent[100000+10],size[100000+10];
	
	void make(int v){
	    parent[v]=v;
	    size[v]=1;
	}
	
	int find(int v){
	    if(v==parent[v])return v;
	    return parent[v]=find(parent[v]);
	}
	
	void Union(int a,int b){
	    a=find(a);
	    b=find(b);
	    if(size[a]<size[b]){
	        swap(a,b);
	    }
	    parent[b]=a;
	    size[a]+=size[b];
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])//{0,{1,5}}
    {
       //kruskal algorithm 
       //vector pairs are sort according to the first element
       //{wt,{a,b}}-> this will sort according to the weight(wt) of the node
       
      vector<pair<int, pair<int, int>>> v;
       
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                
                v.push_back({wt,{i,adjNode}});
                
            }
        }
        
        sort(v.begin(),v.end());
        int cost=0;
        for(int i=0;i<V;i++){
            make(i);
        }
        
        for(auto it:v){
            int weight=it.first;
            int node1=it.second.first;
            int node2=it.second.second;
            
            if(find(node1)==find(node2))continue;
            Union(node1,node2);
            cost+=weight;
            
        }
        
        return cost;
       
       
    }
    
};




int main()
{
    int t;
   //in >> t;
   t=1;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}



#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])//{0,{1,5}}
    {
       
        //prim's algorithm
        //priority_queue {{wt,node}} -> {{x1,y1},{x2,y2}.....}
        
       priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
       // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(V,0);
        
        int sum=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(!vis[node]){
                vis[node]=1;
                sum+=wt;
               for(auto child:adj[node]){
                   int adjNode=child[0];
                   int edgeW=child[1];
                   if(!vis[adjNode]){
                       pq.push({edgeW,adjNode});
                   }
                   
               }
            }
        }
        
        return sum;
    }
    
};




int main()
{
    int t;
    t=1;
    //cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}



lab-04

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
int n, m;
vector<vector<pair<int,int>>> g;
vector<int> dist;
const int N = 1e17;
 
void dijkstra()
{
	for(int i = 0; i <= n; ++i)
	{
		dist[i] = N;
	}
 
	priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > pq;
	dist[0] = 0;
	pq.push({0,0});//{dist,city}
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(dist[u] < d) continue;
		for(auto child: g[u])
		{
			int v = child.first;
			int c = child.second;
	        if(c+d<dist[v]){
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
 
		}
	}
 
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	dist.resize(n+1);
	for(auto i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	dijkstra();
	for(int i = 0; i <n; ++i )
	{
	    if(dist[i]!=N)
		cout << i<<": "<<dist[i] << endl;
		else
		cout<<i<<": "<<-1<<endl;//this case will never occur here
	}
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);


 const int inf=1e9+10;
int main(){
            eyasir2047
          ll n,m;
          cin>>n>>m;
          vector<vector<pair<ll,ll>>>adj(n+1);
          //vector<vector<ll>>v;
          //{u,{v,w}}
          //{v,{u,w}}
          for(ll i=0;i<m;i++){
              ll u,v,w;
              cin>>u>>v>>w;
              adj[u].push_back({v,w});
              adj[v].push_back({u,w});
          }
        
        
        vector<ll>dt(n+1,1e11+10);
        vector<ll>parent(n+1);
       // vector<bool>visited(n+1,false);
        for(ll i=0;i<=n;i++){
            parent[i]=i;
        }


        for(ll i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end());
        }
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        ll source=0;
        dt[source]=0;
        pq.push({0,source});
      //  visited[source]=true;
        
        while(!pq.empty()){
            auto it=pq.top();
            ll node=pq.top().second;
            ll dist=pq.top().first;
            pq.pop();
          //  if(!visited[node]){
               // visited[node]=true;
            for(auto child:adj[node]){
                ll adjNode=child.first;
                ll edgeW=child.second;
                if(edgeW+dist<dt[adjNode]){
                    dt[adjNode]=dist+edgeW;
                    pq.push({dt[adjNode],adjNode});
                    parent[adjNode]=node;
                }
           // }
            }
        }
        
        if(dt[1]==1e11+10){
            //cout<<-1<<endl;
            //cout<<"***"<<endl;
            cout<<"NOT REACHABLE"<<endl;
        }
        else{
            
        vector<ll>ans;
        ll i=1;
        while(parent[i]!=i){
            ans.push_back(i);
            i=parent[i];
        }
        ans.push_back(source);
        reverse(ans.begin(),ans.end());
        
       for(auto i:ans)cout<<i<<" ";
        cout<<endl;
          
        }  
          
                 
        
      
     
      

    return 0;
}

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
//int q;
 //all source shortest path-> floyd warshall algorithm
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	for(int i = 0; i < n; ++i)
	{
		g[i].resize(n+1);
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			//g[i][j] = g[j][i] = INF;//if i==j, g[i][j]=0 as for the global variable
            g[i][j]=INF;
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		//g[u][v] = g[v][u] = min(g[u][v],c);//taking the minimum one
        g[u][v]=min(g[u][v],c); 
	}
    int q;
    cin>>q;
 
	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i <  n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
			}
		}
	}

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
 
	for(int i = 0; i < q; ++i)
	{
		int u, v;
		cin >> u >> v;
        if(u==v){
            cout<<0<<endl;
            continue;
        }
		if(g[u][v] == INF)
        {
            //cout<<"***"<<endl; 
			g[u][v] = -1;
        }

        if(g[u][v]==-1){
            cout<<"Impossible"<<endl;
        }else
		cout << g[u][v] << endl;
            
	}
}

lab-05

#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
int q;
 //all source shortest path-> floyd warshall algorithm
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m ;
	g.resize(n+1);
	for(int i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	
	for(int i = 0; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			g[i][j] = g[j][i] = INF;//if i==j, g[i][j]=0 as for the global variable
			
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = min(g[u][v],c);//taking the minimum one 
	}
 
	for(int k = 0; k <= n; ++k)
	{
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
			}
		}
	}

   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         if(i==j)continue;
         if(g[i][j]!=INF)
         cout<<i<<" to "<<j<<" : "<<g[i][j]<<endl;
         else 

         cout<<i<<" to "<<j<<" : "<<"infinity"<<endl;
      }
   }
 
//	for(int i = 0; i < q; ++i)
	//{
		//int u, v;
		//cin >> u >> v;
	//	if(g[u][v] == INF) 
		//	g[u][v] = -1;
		//cout << g[u][v] << endl;
	//}

   return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
int q;
 //all source shortest path-> floyd warshall algorithm
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m ;
	g.resize(n+1);
	for(int i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	
	for(int i = 0; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			g[i][j] = g[j][i] = INF;//if i==j, g[i][j]=0 as for the global variable
			
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = min(g[u][v],c);//taking the minimum one 
	}
 
	for(int k = 0; k < n; ++k)
	{
      int sum=0;
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
			}

		}
      
         for(int i = 0; i <=k; ++i)
		{
			for(int j = 0; j <=k; ++j)
			{
			//	g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
         if(g[i][j]!=INF){
            sum+=g[i][j];
         }
			}
        

		}
       cout<<sum/2<<endl;
      
      

	}

 
//	for(int i = 0; i < q; ++i)
	//{
		//int u, v;
		//cin >> u >> v;
	//	if(g[u][v] == INF) 
		//	g[u][v] = -1;
		//cout << g[u][v] << endl;
	//}

   return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
int q;
 //all source shortest path-> floyd warshall algorithm
  bool cycle=false;
struct Edge{
   int a,b,cost;
};
vector<Edge>edges(n+10);


 void solve(){

   vector<int> dist(n + 1, INF);
    dist[1] = 0;
  

    for (int i = 0; i < (n - 1); i++) {
       // bool any=false;
        for (Edge e : edges) {
            if (dist[e.a] != INF ) {
               dist[e.b]=min(dist[e.b],dist[e.a]+e.cost);
                
           //     any=true;
            }
        }
       //if(!any)break;
    }

    

    for (Edge e : edges) {
        if (dist[e.a] != INF && dist[e.a] + e.cost< dist[e.b]) {
            cycle=true;
            break;
        }
    }


 }


 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m ;
	g.resize(n+1);
	for(int i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			//g[i][j] = g[j][i] = INF;//if i==j, g[i][j]=0 as for the global variable
			g[i][j]=INF;
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		//g[u][v] = g[v][u] = min(g[u][v],c);//taking the minimum one
      g[u][v]=min(g[u][v],c); 
      edges[i].a=u;
      edges[i].b=v;
      edges[i].cost=min(edges[i].cost,c);
	}


   solve();
   if(cycle){
      cout<<"not possible"<<endl;
   }else{

 
	for(int k = 0; k <= n; ++k)
	{
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
			}
		}
	}

   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         if(i==j)continue;
         if(g[i][j]!=INF)
         cout<<i<<" to "<<j<<" : "<<g[i][j]<<endl;
         else 

         cout<<i<<" to "<<j<<" : "<<"infinity"<<endl;
      }
   }
   } 
//	for(int i = 0; i < q; ++i)
	//{
		//int u, v;
		//cin >> u >> v;
	//	if(g[u][v] == INF) 
		//	g[u][v] = -1;
		//cout << g[u][v] << endl;
	//}

   return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
int q;
 //all source shortest path-> floyd warshall algorithm
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m ;
	g.resize(n+1);
	for(int i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	
	for(int i = 0; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			g[i][j] = g[j][i] = INF;//if i==j, g[i][j]=0 as for the global variable
			
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = min(g[u][v],c);//taking the minimum one 
	}

   int r;
   cin>>r;
   vector<int>a(r);

   for(int i=0;i<r;i++)cin>>a[i];
 
	for(int k = 0; k <= n; ++k)
	{
		for(int i = 0; i <= n; ++i)
		{
			for(int j = 0; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
			}
		}
	}


   int sum=0;
   int k=0;
   for(int i=0;i<r-1;i++){
    //  cout<<g[a[k]][a[k+1]]<<endl;
   
      sum+=g[a[k]][a[k+1]];
      k++;

   }

   cout<<sum<<endl;

   
 
//	for(int i = 0; i < q; ++i)
	//{
		//int u, v;
		//cin >> u >> v;
	//	if(g[u][v] == INF) 
		//	g[u][v] = -1;
		//cout << g[u][v] << endl;
	//}

   return 0;
}


detect cycle in a directed graph

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;

  bool dfs(int node,int  vis[],int pathVis[],vector<int>adj[]){
      vis[node]=1;
      pathVis[node]=1;
      
      for(auto child:adj[node]){
          if(!vis[child]){
              if(dfs(child,vis,pathVis,adj)==true)return true;
          }
          //visited and same path
          else if(pathVis[child]){
              return true;
          }
      }
      
      pathVis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true)return true;
            }
        }
        
        return false;
    }


    undirected graph(bfs)

    #include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;


  
    // Function to detect cycle in an undirected graph.
    
    bool detect(vector<int>adj[],bool vis[],int src){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto child: adj[node]){
                if(!vis[child]){
                    vis[child]=1;
                    q.push({child,node});
                }else if(parent!=child){
                    return true;
                }
            }
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(detect(adj,vis,i))return true;
            }
        }
        return false;
    }

    undirected graph(dfs)

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;

    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int>adj[],bool vis[],int node,int parent){
       vis[node]=1;
       
       for(auto child:adj[node]){
           if(!vis[child]){
               vis[child]=1;
               if(dfs(adj,vis,child,node))return true;
           }else if(child!=parent){//vis[child]==true
               return true;
           }
       }
       
       return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(dfs(adj,vis,i,-1))return true;
            }
        }
        return false;
    }

course sechedule-2
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topological sort 
        int n=numCourses;
        vector<vector<int>>adj(n);

        for(int i=0;i<prerequisites.size();i++){
               adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }


     
       vector<int>indegree(n,0);
	    
	    for(int i=0;i<n;i++){
	        for(auto child:adj[i]){
	            indegree[child]++;
	        }
	    }
	    
	    // for(int i=0;i<n;i++){
	    //     cout<<i<<": "<<indegree[i]<<" "<<endl;
	    // }
	   
	    
	    
	     queue<int>q;
	     
	     for(int i=0;i<n;i++){
	         if(indegree[i]==0){
	             q.push(i);
	         }
	     }
	     
	     vector<int>ans;
	     
	     while(!q.empty()){
	         int node=q.front();
	         q.pop();
	         ans.push_back(node);
	         
	         for(auto child:adj[node]){
	             indegree[child]--;
	             if(indegree[child]==0){
	                 q.push(child);
	             }
	         }      
	     }
	    
        if(ans.size()==n)
       return ans;

       return {};



    }
};

Critical connections

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
//briges in a graph
class Solution {
public:
void dfs(int curr,vector<int>adj[],bool vis[],int dt[],int low[],int time,int parent,  vector<vector<int>>&ans){
    vis[curr]=1;
    time++;
    dt[curr]=low[curr]=time;
    

    for(auto child:adj[curr]){
        if(parent==child)continue;
        else if(!vis[child]){
            dfs(child,adj,vis,dt,low,time,curr,ans);
            low[curr]=min(low[curr],low[child]);
            if(dt[curr]<low[child]){
                    ans.push_back({curr,child});
            }
        }
        else{//vis[child]
                low[curr]=min(low[curr],dt[child]);//->articulation point
        }
    }
   

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int dt[n];
        int low[n];
        int time=0;
        bool vis[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        
        vector<vector<int>>ans;

        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,dt,low,time,-1,ans);
            }
        }
        return ans;

    }
};

Building roads
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MAX 100050
ll n,m;
ll cc=0;
vector<bool>vis(MAX,false);
vector<vector<ll>>g(MAX);
 
 
void dfs(ll node){
    vis[node]=1;
    for(auto child:g[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
 
 
int main(){
    cin>>n>>m;
    
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
  vector<ll>ans;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            cc++;
            ans.push_back(i);
            dfs(i);
        }
    }
    
    cout<<cc-1<<endl;
  
    if(cc>1){
       for(ll i=0;i<ans.size()-1;i++){
           cout<<ans[i]<<" "<<ans[i+1]<<endl;
       }
    }
  
   
    
    
    return 0;
}

Building teams
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
vector<int> color;
vector<bool> vis;
 //bipartite
bool dfs(int u, int c, int par)
{
	vis[u] = true;
	color[u] = c;
 
	for(auto child: g[u])
	{
		if(child == par) continue;
		if(color[child] == 0)
			{
			    if(color[u]==1)c=2;
			    else if(color[u]==2)c=1;
			    //if(!dfs(child, (color[u]^3), u)) 
			    if(!dfs(child,c,u))
				return false;
			}
		if(color[child] == color[u]) 
			return false;
	}
	return true;
}
 
bool color_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(!dfs(i,1,-1)) 
				return false;
	}
	return true;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	color.resize(n+1);
	vis.resize(n+1);
 
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool ans = color_all();
	if(!ans)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for(int i = 1; i <=n ; ++i)
	{
		cout << color[i] << " ";
	}
 
}

Course Schedule
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<int> degree;
//priority_queue<int, vector<int>, greater<int>> pq;
queue<int>pq;
vector<vector<int>> g;
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n+1);
	degree.resize(n+1);
 
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		++degree[v];
	}
 
	for(int i = 1; i <= n; ++i)
	{
		if(degree[i]==0)
			pq.push(i);
	}
	
	vector<int> ans;
	while(!pq.empty())
	{
		int u = pq.front();
		pq.pop();
		ans.push_back(u);
		for(auto child: g[u])
		{
			--degree[child];
			if(degree[child]==0) pq.push(child);
		}
	}
 
	if(ans.size() != n)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		for(auto it: ans)
			cout << it << " ";
	}
}

Counting rooms

#include <bits/stdc++.h>
using namespace std;
 
int n, m, answer = 0;
char grid[1010][1010];
 
void  DFS (int i, int j) {
  if (i < 0) return;
  if (j < 0) return;
  if (i >= n) return ;
  if (j >= m) return;
  if (grid[i][j] == '#') return;
  
  grid[i][j]='#';
  
    DFS(i+1,j);
    DFS(i-1,j);
    DFS(i,j-1);
    DFS(i,j+1);
 
}
 
 
int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        cin >> grid[i][j];
      
      }
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < m ; j++) {
        if (grid[i][j] == '.') {
            answer++;
          DFS(i, j);
          
        }
      }
    }
    cout << answer << endl;
    return 0;
}

Labyrinth
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll n,m;
vector<vector<bool>>vis;
vector<vector<pair<ll,ll>>>path;//2D vector with pair
vector<pair<ll,ll>>moves={{-1,0},{1,0},{0,-1},{0,1}};
ll sx,sy,ex,ey;
 
bool isValid(ll x,ll y){
    if(x<0 || x>=n || y<0 || y>=m)return false;
    if(vis[x][y])return false;
    return true;
}
 
void bfs(){
    queue<pair<ll,ll>>q;
    q.push({sx,sy});
    while(!q.empty()){
        ll cx=q.front().first;
        ll cy=q.front().second;
        q.pop();
        for(auto mv:moves){
            ll childx=mv.first;
            ll childy=mv.second;
            if(isValid(childx+cx,childy+cy)){
                vis[childx+cx][childy+cy]=true;
                q.push({childx+cx,childy+cy});
                path[childx+cx][childy+cy]={childx,childy};
            }
        }
        
    }
    
}
 
int main(){
    cin>>n>>m;
    vis.resize(n);
    path.resize(n);
    for(ll i=0;i<n;i++){
        path[i].resize(m);
        vis[i].resize(m);
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='#'){
                vis[i][j]=true;
            }
            if(c=='A'){
                sx=i;
                sy=j;
            }
            if(c=='B'){
                ex=i;
                ey=j;
            }
        }
    }
    
    bfs();
    
    if(!vis[ex][ey]){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    
    vector<pair<int,int>>ans;
    pair<int,int>end={ex,ey};
    
    while(end.first!=sx || end.second!=sy){
        ans.push_back(path[end.first][end.second]);
        end.first-=ans.back().first;
        end.second-=ans.back().second;
    }
    
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    
    for(auto it:ans){
        if(it.first==-1 && it.second==0)cout<<"U";
        else if(it.first==+1 && it.second==0)cout<<"D";
        else if(it.first==0 && it.second==-1)cout<<"L";
        else if(it.first==0 && it.second==+1)cout<<"R";
    }
    cout<<endl;
    
    
    return 0;
}
Labyrinth2
#include<bits/stdc++.h>
using namespace std;
int n, m;
 
vector<vector<pair<int,int>>> path;
vector<vector<bool>> vis;
 
int sx, sy, ex, ey;
 
vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};
 
bool isValid(int x, int y)
{
	if(x<0 or x >= n or y <0 or y>=m)
		return false;
	if(vis[x][y])
		return false;
	return true;
}
 
void bfs()
{
	queue<pair<int,int>> q;
	q.push({sx,sy});
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for(auto mv: moves)
		{
			int mvx = mv.first;
			int mvy = mv.second;
			if(isValid(cx+mvx, cy+mvy))
			{
				q.push({cx+mvx, cy+mvy});
				vis[cx+mvx][cy+mvy] = true;
				path[cx+mvx][cy+mvy] = {mvx,mvy};
			}
		}
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	path.resize(n);
	vis.resize(n);
	for(int i = 0; i < n; ++i)
	{
		path[i].resize(m);
		vis[i].resize(m);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			path[i][j] = {-1,-1};
			char c; cin >> c;
			if(c == '#')
			{
				vis[i][j] = true;
			}
			if(c == 'A')
			{
				sx = i; sy = j;
			}
			if(c == 'B')
			{
				ex = i; ey = j;
			}
		}
	}
	bfs();
 
	if(!vis[ex][ey])
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
 
	vector<pair<int,int>> ans;
	pair<int,int> end = {ex,ey};
 
	while(end.first != sx or end.second != sy)
	{
		ans.push_back(path[end.first][end.second]);
		end.first -= ans.back().first;
		end.second -= ans.back().second;	
	}
 
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		if(c.first == 1 and c.second ==0)
		{
			cout << 'D';
		}
		else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
		}
	}
}
roundtrip
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;


void dfs(int curr,vector<vector<int>>&adj,vector<int>&dt,vector<int>&low,stack<int>&st,
	vector<bool>&instack,vector<vector<int>>&ans){
	    static int time=0;
	    dt[curr]=low[curr]=time;
	    time++;
	    st.push(curr);
	    instack[curr]=true;
	    
	    for(auto child:adj[curr]){
	        if(dt[child]==-1){
	            dfs(child,adj,dt,low,st,instack,ans);
	            low[curr]=min(low[curr],low[child]);
	        }
	       else if(instack[child]){//back edge condition->already visited+ present in the stack
	           low[curr]=min(low[curr],dt[child]);
	           cout<<"back edges: "<<curr<<" "<<child<<endl;
	       }
           else {//cross edge -> //already visited but not present in the stack 
           //else if(!instack[child])
           //cout<<"cross edges: "<<curr<<" "<<child<<endl;

           }
	    }
	  
	    
	    if(low[curr]==dt[curr]){// curr is the head of SCC
	        vector<int>res;
	        while(st.top()!=curr ){
	            res.push_back(st.top());
	            instack[st.top()]=false;
	            st.pop();
	        }
	        
	            res.push_back(st.top());
	            instack[st.top()]=false;
	            st.pop();
	        sort(res.begin(),res.end());
	        ans.push_back(res);
	    }
	}
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<vector<int>>&adj)
    {
        //code here
        //tarjan's algorithm-> bridge, articulation point, strongly connected components and 
        // topological sort 
        vector<int>dt(V+1,-1);
        vector<int>low(V+1,-1);
        vector<bool>instack(V+1,false);
        stack<int>st;
       
        vector<vector<int>>ans;
        for(int i=1;i<=V;i++){
            if(dt[i]==-1){
                dfs(i,adj,dt,low,st,instack,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }

int main(){
    
    cin>>n>>m;
    
    vector<vector<int>>adj(n+1);
  
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
   vector<vector<int>>ans;
   ans=tarjans(n,adj);

   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        if(j==ans[i].size()-1){
            cout<<ans[i][j];
            continue;
        }
        cout<<ans[i][j]<<" ";
    }
    cout<<",";
   }


   
    
   
        
        
        return 0;
    
}


cycle finding

#include<bits/stdc++.h>
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
const ll inf = 1LL<<62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

void solve(){
    int n,m; see(n,m);
    vc<tuple<int,int,int>> e;
    rep(i,0,m){
        int a,b,w; see(a,b,w);
        e.pb({a,b,w});
    }
    //bellman-ford algorithm
    int dis[n+1], par[n+1]={0};
    rep(i,1,n+1) dis[i]=inf;
    dis[1]=0; 
    int f;
    rep(i,1,n+1){
        f=0;
        for (auto [a,b,w]: e){
            if (dis[a]+w<dis[b]){
                dis[b] = dis[a]+w;
                par[b] = a;
                f=b;
            }
        }
    }
    if (!f){put("NO"); return;}
    else{
        putl("YES");
        vi cyc;
        rep(i,1,n+1) f = par[f];
        for (int x = f;; x = par[x]){
            cyc.pb(x);
            if (x==f && cyc.sz>1) break;
        }
        
        reverse(all(cyc));
        for (auto i: cyc) put(i);
    }
}    
signed main(){
    IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        //cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}

flight discount
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define rep(a,b) for(ll i=a;i<=b;i++)
#define INF (1LL<<60)
const int N=2e5+100;


vector<pair<ll,ll>>adj[N+10],adj2[N+10];//{u,{v,w}}
vector<pair<pair<ll,ll>,ll>>ans; //{{u,v},w}
ll dt[N+10];
ll dt2[N+10];

int main(){
    ll n,m;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj2[v].push_back({u,w});
        ans.push_back({{u,v},w});
    }
    
    po(i,n)dt[i]=INF;
    
    dt[1]=0;
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    
    pq.push({0,1});
    
    while(!pq.empty()){
        ll dist=pq.top().first;
        ll curr=pq.top().second;
        pq.pop();
        if(dist>dt[curr])continue;
        for(auto child:adj[curr]){
            ll adjNode=child.first;
            ll adjW=child.second;
            
            if(dist+adjW<dt[adjNode]){
                dt[adjNode]=dist+adjW;
                pq.push({dt[adjNode],adjNode});
            }
        }
    }
    //now the queue is empty, so we can use the same queue
    po(i,n)dt2[i]=INF;
    
    dt2[n]=0;
    
    pq.push({0,n});
    
     while(!pq.empty()){
        ll dist2=pq.top().first;
        ll curr2=pq.top().second;
        pq.pop();
        
        if(dist2>dt2[curr2])continue;
        
        for(auto child:adj2[curr2]){
            ll adjNode2=child.first;
            ll adjW2=child.second;
            
            if(dist2+adjW2<dt2[adjNode2]){
                dt2[adjNode2]=dist2+adjW2;
                pq.push({dt2[adjNode2],adjNode2});
            }
        }
    }
    
    
    ll mini=1e18+10;
    
    // po(i,n){
    //     cout<<dt[i]<<" ";
    // }
    // cout<<endl;
    // po(i,n){
    //     cout<<dt2[i]<<" ";
    // }cout<<endl;
    
    for(int i=0;i<m;i++){
        ll uu=ans[i].first.first;
        ll vv=ans[i].first.second;
        ll ww=ans[i].second;
       // cout<<uu<<" "<<vv<<" "<<ww<<endl;
       // cout<<dt[uu]+dt2[vv]+floor(ww/2)<<endl;
        mini=min(mini,dt[uu]+dt2[vv]+ww/2);
    }
    
    cout<<mini<<endl;
    
    
    
    
    return 0;
}
flight routines
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define rep(a,b) for(ll i=a;i<=b;i++)
#define INF (1LL<<60)
#define eyasir2047 ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N=2e5+100;

vector<vector<pair<ll,ll>>>adj;
vector<vector<ll>>dt;

int main(){
    
    eyasir2047
    
    ll n,m,k;cin>>n>>m>>k;
    
    adj.resize(n+1);
    dt.resize(n+1);
    
    po(i,n){
        dt[i].resize(k);
        fo(j,k){
            dt[i][j]=INF;
        }
    }
    
    dt[1][0]=0;
    
    fo(i,m){
        ll u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
   
   pq.push({0,1});
   
   while(!pq.empty()){
       ll curr=pq.top().second;
       ll w=pq.top().first;
       pq.pop();
       
       if(w>dt[curr][k-1])continue;
       
       for(auto child: adj[curr]){
           ll adjnode=child.first;
           ll adjW=child.second;
           if(w+adjW<dt[adjnode][k-1]){
               dt[adjnode][k-1]=w+adjW;
               pq.push({dt[adjnode][k-1],adjnode});
               sort(dt[adjnode].begin(),dt[adjnode].end());
           }
       }
   }
   
   
   fo(i,k){
       cout<<dt[n][i]<<" ";
   }
   cout<<endl;
    
    
    
      
 
    
    return 0;
}
message route
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define MAX 100050
ll n,m;
vector<bool>vis(MAX,false);
vector<vector<ll>>g(MAX);
vector<ll>parent(MAX,-1);
 
void bfs(){
     queue<ll>q;
     q.push(1);
     vis[1]=true;
     
     while(!q.empty()){
         auto node=q.front();
         q.pop();
         for(auto child:g[node]){
             if(!vis[child]){
                 vis[child]=true;
                 parent[child]=node;
                 q.push(child);
             }
         }
     }
}
 
int main(){
    cin>>n>>m;
    
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    bfs();
    
    stack<ll>st;
    ll node=n;
    while(node!=-1){
        st.push(node);
        node=parent[node];
    }
    if(st.size()==1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<st.size()<<endl;
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
    
 
    
    
    return 0;
}
road construction
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const ll N=1e7+10;
ll parent[N];
ll size2[N];
	
	void make(ll v){
	    parent[v]=v;
	    size2[v]=1;
	}
	
	int find(ll v){
	    if(v==parent[v])return v;
	    return parent[v]=find(parent[v]);
	}
	
	bool Union(ll a,ll b){
	    a=find(a);
	    b=find(b);
	    if(a==b)return false;
	    if(size2[a]<size2[b]){
	        swap(a,b);
	    }
	    parent[b]=a;
	    size2[a]+=size2[b];
	    return true;
	}
	
 
int main(){
    ll n,m;
    cin>>n>>m;
    
    for(ll i=1;i<=n;i++)make(i);
    
   ll components=n;
   ll maxi=1;
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        if(Union(u,v)){
            components--;
            maxi=max(maxi,size2[parent[u]]);
            maxi=max(maxi,size2[parent[v]]);
        }
        cout<<components<<" "<<maxi<<endl;
        
    }
    
   
    return 0;
}
road reparation
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const ll N=1e7+10;
ll parent[N];
ll size2[N];
	
	void make(ll v){
	    parent[v]=v;
	    size2[v]=1;
	}
	
	int find(ll v){
	    if(v==parent[v])return v;
	    return parent[v]=find(parent[v]);
	}
	
	void Union(ll a,ll b){
	    a=find(a);
	    b=find(b);
	    if(size2[a]<size2[b]){
	        swap(a,b);
	    }
	    parent[b]=a;
	    size2[a]+=size2[b];
	}
	
    
void getMinimumCost(ll n, ll m, vector<vector<ll>> &connections) {
  //	Write your code here.
  // coding ninjas
  //{u,v,w}
    vector<pair<ll, pair<ll, ll>>> v;
	//{wt,{u,v}}
		ll V=n;
 
	for(auto &it:connections){
		ll i=it[0];
		ll adjNode=it[1];
		ll wt=it[2];
		v.push_back({wt,{i,adjNode}});
	}
       
        
        
        sort(v.begin(),v.end());
        ll cost=0;
        for(ll i=1;i<=V;i++){
            make(i);
        }
        
		int numEdges=0;
        for(auto it:v){
            ll weight=it.first;
            ll node1=it.second.first;
            ll node2=it.second.second;
           
            if(find(node1)==find(node2))continue;
            Union(node1,node2);
            cost+=weight;
			numEdges++;
			
			}
 
		
		
        if(numEdges==n-1){
            cout<<cost<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
       
 
		
}
 
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj;
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    
    getMinimumCost(n,m,adj);
    return 0;
}
round trip -2
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
 
vector<int> vis;
 
stack<int> st;
 
vector<bool> pathVis;
 
bool dfs(int u)
{
	vis[u] = true;
	st.push(u);
	pathVis[u] = true;
	for(auto child: g[u])
	{
		if(!vis[child])
			if(dfs(child))
				return true;
 
		if(pathVis[child])
		{
			st.push(child);
			return true;
			//no more dfs;
		}
	}
    st.pop();
	pathVis[u] = false;
	return false;
	//no cycle was detected
}
 
 
void visit_all()
{
	for(int u = 1; u <= n; ++u)
	{
		if(!vis[u])
		{
			if(dfs(u))
				break;
		}
	}
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	pathVis.resize(n+1);
	
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
	//	g[u].insert(v);
	g[u].push_back(v);
	}
	visit_all();
	if(st.empty())
	{		
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	vector<int> ans;
	int temp = st.top();
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
		if(ans.back() == temp and ans.size() != 1)
			break;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto u: ans)
	{
		cout << u << " ";
	}
 
	
}
round trip
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
 
int n, m;
int sv, ev;//sv=starting vertex,ev=ending vertex
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
 
 
bool dfs(int u, int par)
{
	vis[u] = true;
	parent[u] = par;
	for(auto child: g[u])
	{
		if(child == par) continue;
		if(!vis[child]) {
			if(dfs(child,u)) 
				return true;
		}
				
	   else if(vis[child]) //if vis[child] and that is not a parent, that means there
	   //is a cycle present there
		{
			sv = child; //starting vertex
			ev = u; //ending vertex
			return true;
		} 
	}
	return false;
}
 
 
bool visit_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	parent.resize(n+1);
	for(int i =0 ; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	if(!visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	int i = ev;
	vector<int> ans;
	ans.push_back(ev);
	while(i != sv)
	{
		ans.push_back(parent[i]);
		i = parent[i];
	}
	ans.push_back(ev);
	cout << ans.size() << endl;
	for(auto it: ans)
	{
		cout << it << " ";
	}
 
}
shortest path -1
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
int n, m;
vector<vector<pair<int,int>>> g;
vector<int> dist;
const int N = 1e17;
 
void dijkstra()
{
	for(int i = 0; i <= n; ++i)
	{
		dist[i] = N;
	}
 
	priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > pq;
	dist[1] = 0;
	pq.push({0,1});//{dist,city}
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(dist[u] < d) continue;
		for(auto child: g[u])
		{
			int v = child.first;
			int c = child.second;
	        if(c+d<dist[v]){
				dist[v] = c+d;
				pq.push({dist[v], v});
			}
 
		}
	}
 
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	dist.resize(n+1);
	for(auto i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	dijkstra();
	for(int i = 1; i <=n; ++i )
	{
	    if(dist[i]!=N)
		cout << dist[i] << " ";
		else
		cout<<-1<<" ";//this case will never occur here
	}
}

shortest path-2

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
int q;
 //all source shortest path-> floyd warshall algorithm
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;
	g.resize(n+1);
	for(int i = 0; i <= n; ++i)
	{
		g[i].resize(n+1);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			g[i][j] = g[j][i] = INF;//if i==j, g[i][j]=0 as for the global variable
			
		}
	}
 
	for(int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u][v] = g[v][u] = min(g[u][v],c);//taking the minimum one 
	}
 
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);//g[i][k]+g[k][j]->i to k,then k to j
			}
		}
	}
 
	for(int i = 0; i < q; ++i)
	{
		int u, v;
		cin >> u >> v;
		if(g[u][v] == INF) 
			g[u][v] = -1;
		cout << g[u][v] << endl;
	}
}


*/