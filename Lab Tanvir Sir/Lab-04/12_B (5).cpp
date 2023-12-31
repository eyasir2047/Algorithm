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