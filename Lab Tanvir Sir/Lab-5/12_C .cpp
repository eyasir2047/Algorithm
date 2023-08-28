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