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
#define eyasir2047 ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N=1e5+10;

vector<int>g[N];
bool visited[N];
 int n,m;
 vector<int>ans(n);


void dfs(int vertex){
   visited[vertex]=true;
   ans.push_back(vertex);
  
    for(auto child:g[vertex]){
      
        
        if(!visited[child]){
            
             dfs(child);
             
        }
    
    }
    
    
}

int main(){
   
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
       
}
           
            dfs(0);
            
            
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;

 return 0;
}




































/*

kruskal 
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	int parent[100000],size[100000];
	
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

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
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


// } Driver Code Ends

prim algorithm

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])//{0,{1,5}}
    {
        // code here
        //prim's algorithm
        //priority_queue {{wt,node}} -> {{x1,y1},{x2,y2}.....}
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
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

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
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


// } Driver Code Ends

DFS
#include<iostream>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int>g[N];
bool visited[N];
 int n,m;
 vector<int>ans(n);


void dfs(int vertex){
    //
   visited[vertex]=true;
   ans.push_back(vertex);
  // cout<<vertex<<" ";
    for(auto child:g[vertex]){
        //cout<<vertex<<" "<<child<<endl;
        
        if(!visited[child]){
            //
             dfs(child);
             //
        }
    
    }
    //
    
}

int main(){
   
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
       
}
           
            dfs(0);
            
            
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;

 return 0;
}

BFS

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
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

Topological sort(Khan's algorithm)

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
int vis[N];

int n,m;
	    
//kahn's algorithm-> bfs	    

int main(){
    
    cin>>n>>m;
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    
    int indegree[n]={0};
	    
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
	    
     
     for(int i=0;i<n;i++){
         cout<<ans[i]<<" ";
     }
     cout<<endl;
        
        
        return 0;
    
}

Topological sort(DFS)

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
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
	        cout<<ans[i]<<" ";
	    }
    cout<<endl;
    
        
        
        return 0;
    
}

SCC(Tarjan's)

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
	       }
           else {//cross edge -> //already visited but not present in the stack 
           //else if(!instack[child])

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
        vector<int>dt(V,-1);
        vector<int>low(V,-1);
        vector<bool>instack(V,false);
        stack<int>st;
       
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(dt[i]==-1){
                dfs(i,adj,dt,low,st,instack,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }

int main(){
    
    cin>>n>>m;
    
    vector<vector<int>>adj(n);
  
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
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

SCC(Kosaraju algorthim)

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
//vector<vector<int>>ans;

void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
        vis[node]=1;
        //discovery time
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,vis,st,adj);
            }
        }
        //finishing time
        st.push(node);
    }
    
    void dfs3(int node,vector<int>&vis,vector<int>adjR[]){
  
         vis[node]=1;
        
        cout<<node<<" ";
         
        for(auto child: adjR[node]){
           
            if(!vis[child]){
                
                dfs3(child,vis,adjR);
            }
        }
       // cout<<node<<" ";
       
        
    }
    
   
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //kosaraju algorithm-> 1) sort according to time and store it into the stack
        //2) reverse the edge
        //3) again dfs and count the scc
        
        vector<int>vis(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        vector<int>adjR[V];
        //i->child, now child->i
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto child:adj[i]){
                adjR[child].push_back(i);
            }
        }
         
        
        int scc=0;
        
      
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
         // cout<<node<<" ";
            if(!vis[node]){
                scc++;
             //   cout<<endl;
                dfs3(node,vis,adjR);
            }
        }
     //  cout<<endl;
        return scc;
        
        
        
    }

   

int main(){
    
    cin>>n>>m;
    
    vector<vector<int>>adj(n);
  
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
    
    int a=kosaraju(n,adj);
    cout<<endl;
    cout<<a<<endl;
   
    
   
        
        
        return 0;
    
}

Euler path

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<vector<pair<int,int>>>adj(N);
vector<int>ans;

int idx[N];
int out[N];
int vis[N];

//euler path

void dfs(int node){
    while(idx[node]<adj[node].size()){
        pair<int,int>y=adj[node][idx[node]];
        idx[node]++;
        if(!vis[y.second]){
            vis[y.second]=1;//y.second=index
            dfs(y.first);//y.first=child
        }
    }
    ans.push_back(node);
}
int main(){
    int t=1;
    //cin>>t
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v,i});
            out[u]++;
            out[v]--;
        }
        
        
    dfs(1);
   // cout<<out[1]<<" "<<out[n]<<" "<<ans.size()<<" "<<m+1<<endl;
        
    if(out[1]!=1 || out[n]!=-1 || ans.size()!=(m+1)){
        cout<<"IMPOSSIBLE"<<endl;
        // cout<<"1"<<endl;
        return 0;
    }
    
    for(int i=2;i<n;i++){
        if(out[i]!=0){
           cout<<"IMPOSSIBLE"<<endl;
         //  cout<<"2"<<endl;
            return 0; 
        }
    }
    
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
        
}
    
    
    return 0;
}

Euler Circuit

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int idx[N],vis[N];

vector<vector<pair<int,int>>>adj(N);
//{u,{v,index}}

vector<int>ans;

//euler circuit

void dfs(int node){
    while(idx[node]<adj[node].size()){
        pair<int,int>y=adj[node][idx[node]];
        idx[node]++;
        if(!vis[y.second]){
            vis[y.second]=1;//y.second=index
            dfs(y.first);//y.first=child
        }x
    }
    ans.push_back(node);
}

int main(){
    int t=1;
    //cin>>t
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size()%2!=0){
                cout<<"IMPOSSIBLE";//as a euler circuit ,there is no odd degree edge
                return 0;
            }
        }
        
        dfs(1);
        
        if(ans.size()!=(m+1)){
            cout<<"IMPOSSIBLE";
                return 0;
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        
        
    
    }
    
    return 0;
}

Articulation Point -I
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void dfs(int curr,bool vis[],vector<int>adj[],int dt[],int low[],int time,int par,vector<int>&ap){
      vis[curr]=1;
      time++;
      dt[curr]=low[curr]=time;
      int children=0;
      
      for(auto child: adj[curr]){
          if(par==child)continue;
          else if(vis[child]){
              low[curr]=min(low[curr],dt[child]);
          }else{// !vis[child]
              dfs(child,vis,adj,dt,low,time,curr,ap);
              low[curr]=min(low[curr],low[child]);
              if(dt[curr]<=low[child] && par!=-1){
                 ap[curr]=1;
              }
              children++;
          }
      }
      
      if(par==-1 && children>1){
       ap[curr]=1;
      }
      
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int dt[V];
        int low[V];
        int time=0;
        int parent=-1;
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
        }
       vector<int>ap(V,0);
       
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,dt,low,time,parent,ap);
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

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
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
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends

Articulation Point -II

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
        // Code here
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
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
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends


Bridges(tarjans)

#include<bits/stdc++.h>
using namespace std;
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
                low[curr]=min(low[curr],low[child]);//->articulation point
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

Bridges


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;
    vector<int> visited;
    vector<int> disc;
    vector<int> low;
    int time;
    vector<vector<int>>ans;
    

public:
    Graph(int vertices) : V(vertices), adjList(vertices), visited(vertices, 0), disc(vertices, -1), low(vertices, -1), time(0) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void findBridges() {
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
    }

    void dfs(int u, int parent) {
        visited[u] = 1;
        disc[u] = low[u] = time++;
        
        for (int v : adjList[u]) {
            if (v == parent) {
                continue; // Skip the edge to the parent.
            }
            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                  // cout << "Bridge: " << u << " - " << v << endl;
                   ans.push_back({u,v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void print(){
        for(auto i:ans){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int V, E;
   // cout << "Enter the number of vertices: ";
    cin >> V;
   // cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    //cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Bridges in the graph:\n";
    graph.findBridges();
    graph.print();

    return 0;
}


Biconnected component

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, m;
vector< int > adj[N];
int dfn[N], low[N], parent[N], timeStamp;
stack< int > S;
vector< vector<int>> components;

void dfs(int u) {
  dfn[u] = low[u] = ++timeStamp;
  S.push(u);

  for ( int v : adj[u] ) {
    if ( dfn[v] == 0 ) {
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if ( low[v] >= dfn[u] ) {
        vector< int > component;
        int w;
        do {
          w = S.top();
          S.pop();
          component.push_back(w);
        } while (w != v);
        component.push_back(u);
        components.push_back(component);
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
  cin >> n >> m;
  for ( int i = 0; i < m; i++ ) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {//1 based indexing
    if (dfn[i] == 0) {
      dfs(i);
    }
  }
  for (const auto& component : components) {
    for (int v : component) {
      cout << v << " ";
    }
    cout << endl;
  }

  return 0;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    void tarjanBiconnected(int v, int parent, int &time, vector<int>& disc, vector<int>& low, stack<pair<int, int>>& stk);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isBiconnected();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::tarjanBiconnected(int v, int parent, int &time, vector<int>& disc, vector<int>& low, stack<pair<int, int>>& stk) {
    int children = 0;
    disc[v] = low[v] = ++time;
    for (int u : adj[v]) {
        if (u == parent)
            continue;
        if (disc[u] == -1) {
            children++;
            stk.push({v, u});
            tarjanBiconnected(u, v, time, disc, low, stk);

            low[v] = min(low[v], low[u]);

            if (low[u] >= disc[v]) {
                // The edge (v, u) is a bridge.
                // Process the biconnected component.
                while (stk.top() != make_pair(v, u)) {
                    cout << stk.top().first << "-" << stk.top().second << " ";
                    stk.pop();
                }
                cout << stk.top().first << "-" << stk.top().second << " ";
                stk.pop();
                cout << endl;
            }
        } else if (disc[u] < disc[v]) {
            low[v] = min(low[v], disc[u]);
            stk.push({v, u});
        }
    }
}

bool Graph::isBiconnected() {
    vector<int> disc(V, -1), low(V, -1);
    stack<pair<int, int>> stk;
    int time = 0;

    tarjanBiconnected(0, -1, time, disc, low, stk);

    // Check if there are any remaining edges in the stack
    while (!stk.empty()) {
        cout << stk.top().first << "-" << stk.top().second << " ";
        stk.pop();
    }

    return true;
}

int main() {
    int V, E;
    //cout << "Enter the number of vertices: ";
    cin >> V;
   // cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);

    //cout << "Enter the edges (vertex pairs):\n";
    for (int i = 0; i < E; i++) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    cout << "Biconnected components:\n";
    if (g.isBiconnected()) {
        cout << "The graph is biconnected.\n";
    } else {
        cout << "The graph is not biconnected.\n";
    }

    return 0;
}

Dijstra

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
       
        for(ll i=1;i<=n;i++){//self loop
            parent[i]=i;
        }
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        ll source=1;
        dt[source]=0;
        pq.push({0,source});
     
        
        while(!pq.empty()){
            auto it=pq.top();
            ll node=pq.top().second;
            ll dist=pq.top().first;
            pq.pop();
        if(dist>dt[node])continue;
            for(auto child:adj[node]){
                ll adjNode=child.first;
                ll edgeW=child.second;
                if(edgeW+dist<dt[adjNode]){
                    dt[adjNode]=dist+edgeW;
                    pq.push({dt[adjNode],adjNode});
                    parent[adjNode]=node;
                }
          
            }
        }
        
        if(dt[n]==1e11+10)cout<<-1<<endl;
        else{
            
        vector<ll>ans;
        ll i=n;
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

Dijstra's -2
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        int n=V;
         vector <bool> vis(n+1,false);
          int source=S;
          vector<int>dt(n+1,1e9+10);
          dt[source]=0;
     //   priority_queue<int>pq;
     //{u,{v,w}}
     //vector<int>v;
     //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     //{distance,source}
     //priority_queue<datatype,vector<datatype>,comparator>
     
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
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends

Bellman-Ford 


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fo(i, n) for (ll i = 0; i < n; i++)
#define po(i, n) for (ll i = 1; i <= n; i++)
#define rep(a, b) for (ll i = a; i <= b; i++)
//#define INF (1LL << 60)
#define eyasir2047 ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N = 2e5 + 100;
const int INF=1e10+10;

struct Edge {
    int a, b, w;
};

int n, m;
vector<Edge> v;

void solve() {
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    vector<int>parent(n+1,-1);

    for (int i = 0; i < (n - 1); i++) {
       // bool any=false;
        for (Edge e : v) {
            if (dist[e.a] != INF ) {
               dist[e.b]=min(dist[e.b],dist[e.a]+e.w);
                parent[e.b]=e.a;
           //     any=true;
            }
        }
       //if(!any)break;
    }

    bool ans = false;

    for (Edge e : v) {
        if (dist[e.a] != INF && dist[e.a] + e.w < dist[e.b]) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "Negative Cycle present" << endl;
     } //else if(dist[n]==INF){//no path from 1 to n
    //     cout<<"No path"<<endl;
    // }
    else {
        po(i, n){
            if(dist[i]!=INF)cout<<dist[i]<<" ";
            else cout<<"30000"<<" ";
        }
        cout << endl;

        // vector<int>path;
        // for(int curr=n;curr!=-1;curr=parent[curr])
        // path.push_back(curr);

        // reverse(path.begin(),path.end());

        // for(auto it:path)
        // cout<<it<<" ";

        // cout<<endl;


    }
}

int main() {
    eyasir2047
    cin >> n >> m;
    
    v.resize(m+10);
    
    po(i, m) {
        cin >> v[i].a >> v[i].b >> v[i].w;
    }

    solve();
    
    return 0;
}

negative cycle printing(bellman ford)


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fo(i, n) for (ll i = 0; i < n; i++)
#define po(i, n) for (ll i = 1; i <= n; i++)
#define rep(a, b) for (ll i = a; i <= b; i++)
//#define INF (1LL << 60)
#define eyasir2047 ios_base::sync_with_stdio(false); cin.tie(NULL);
const int N = 2e5 + 100;

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "No negative cycle found.";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}

int main() {
    eyasir2047
    cin >> n >> m;
    
    edges.resize(m+10);
    
    po(i, m) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }

    solve();
    
    return 0;
}

//negative cycle detection 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    int S=0;
	    int V=n;
	     vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(u!=1e8 && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(u!=1e8 && dist[u]+wt<dist[v]){
                  return 1;
                }
        }
        
        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

Floyd Warshall Algorithm

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    
	  
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][j]==-1){
	                    matrix[i][j]=1e9;
	                }
	                if(i==j){
	                    matrix[i][j]=0;
	                }
	            }
	        }
	   
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	             //   if(matrix[i][j]==1e9 || matrix[i][k]==1e9)continue;
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	       if(matrix[i][i]<0){
	                
	            }
	        
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9)matrix[i][j]=-1;
	        }
	    }
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends

floyd warshall path printing

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

    
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

    
    return 0;
}

johson algorithm(Fardin)

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


johson 

#include<bits/stdc++.h>
using namespace std;

//johson-> bellmanford and dijkstra
//bellmanford-> 0(V* VE)
//dijktra-> 0(V* Elog(V))
//0(v2E+ VElog(V)) , it is better than Floyd Warshall (O(V^3))

bool negativeCycleExist =false;

vector<int> bellmanFord(vector<vector<pair<int, int>>> &graph, int n) {
    vector<int> h(n+1,INT_MAX);//dis
    h[n] = 0;

    for (int i = 1; i <= n ; ++i) {
        for (int vi = 1; vi <= n; ++vi) {
            for (auto child : graph[vi]) {
                int child_v = child.first;
                int wt = child.second;
                if (h[vi] != INT_MAX && h[vi] + wt < h[child_v]) {
                    h[child_v] = h[vi] + wt;
                }
            }
        }
    }

    //negative cycle exits 
    for (int vi = 1; vi <= n; ++vi) {
        for (auto child : graph[vi]) {
            int child_v = child.first;
            int wt = child.second;
            if (h[vi] != INT_MAX && h[vi] + wt < h[child_v]) {
                negativeCycleExist = true;
                return h;
            }
        }
    }

    return h;//returning the distance vector 
}

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph,int n, int source)
{
    vector<int>dist(n,INT_MAX);
    vector<int> visited(n, 0);
    set<pair<int, int>> st; //why not queue
    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty())
    {
        auto node = *st.begin();//int node=q.front();
        int vi = node.second;
        st.erase(st.begin());

        if (visited[vi])
            continue;
        visited[vi] = 1;

        for (auto child : graph[vi])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[vi] + wt < dist[child_v])
            {
                dist[child_v] = dist[vi] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    return dist;
}

void printSolution(vector<vector<int>>&dist, int n)
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] ==INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}


void johnson(vector<vector<pair<int, int>>> &graph,int n)
{
    for(int i=0;i<n;i++)
    {
       graph[n].push_back({i,0});
    }

    auto h=bellmanFord(graph,n);

    if(negativeCycleExist==true)
    {
        cout<<"Negative cycle exists so shortest path is not possible"<<endl;
        return;
    }

    for(int i=0;i<n;i++)
    {
        for(auto j:graph[i])
        {
            int &wt=j.second;
            //tackling the negative weight, as dijkstra does not work in negative edge
            wt= wt+h[i]- h[j.first];//h--->dist

        }
    }

    vector<vector<int>>shortest(n);

    for(int source=0;source<n;source++)
    {
        shortest[source]=dijkstra(graph,n,source);
    }
    
    printSolution(shortest,n);
}


int main() {
    int n = 4; // Number of vertices
    vector<vector<pair<int, int>>> graph(n+1);

    vector<vector<int> >matrix(4,vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INT_MAX;
        }
    }

    matrix[0][1] = 5;
    matrix[0][3] = 10;
    matrix[1][2] = 3;
    matrix[2][3] = 1;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != INT_MAX) {
                graph[i].push_back({j, matrix[i][j]});
            }
        }
    }

    johnson(graph, n);

    return 0;
}


back edges


#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS and find back edges
bool dfs(vector<vector<int>>& graph, int v, int parent, vector<bool>& visited,vector<int>&ans) {
    visited[v] = true;

    for (int u : graph[v]) {
        if (!visited[u]) {
            if (dfs(graph, u, v, visited,ans))
                return true;
        } else if (u != parent) {
            return true; // Found a back edge
        }
    }

    return false;
}

// Function to find back edges in an undirected graph
bool hasBackEdges(vector<vector<int>>& graph, int n,vector<int>&ans) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(graph, i, -1, visited,ans))
                return true;
        }
    }

    return false;
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Since it's an undirected graph
    }
        vector<int>ans;
        
        hasBackEdges(graph,n,ans);
        for(auto it:ans)cout<<it<<" ";
    // if (hasBackEdges(graph, n,ans)) {
    //     cout << "The graph has back edges (contains cycles)." << endl;
    // } else {
    //     cout << "The graph does not have any back edges (is acyclic)." << endl;
    // }

    return 0;
}
 

back and cross edges

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//int n,m;


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
           cout<<"cross edges: "<<curr<<" "<<child<<endl;

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
        vector<int>dt(V,-1);
        vector<int>low(V,-1);
        vector<bool>instack(V,false);
        stack<int>st;
       
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(dt[i]==-1){
                dfs(i,adj,dt,low,st,instack,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>adj(n);
  
   for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
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





*/
