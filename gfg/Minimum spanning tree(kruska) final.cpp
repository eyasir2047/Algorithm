#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fo(i,n) for(ll i=0;i<n;i++)
#define po(i,n) for(ll i=1;i<=n;i++)
#define all(x) sort(x.begin(),x.end())
#define pb push_back
#define eyasir2047 ios_base::sync_with_stdio(0);cin.tie(NULL);
#define tup tuple<int,int,int>

const int N=1e5+10;
int n,m;
int parent[N],siz[N];
vector<tup>adj;

void make(int v){
    parent[v]=v;
    siz[v]=1;
}

int find(int v){
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(siz[a]>siz[b])swap(a,b);
    
    parent[b]=a;
    siz[a]+=siz[b];
    
}

bool cmp(tup a,tup b){
    auto [ua,va,wa]=a;
    auto [ub,vb,wb]=b;
    return wa<wb;
}

int main(){
    
    eyasir2047
    
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)make(i);
    
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        adj.pb({u,v,w});
    }
    
    sort(adj.begin(),adj.end(),cmp);
    
    int cost=0;
    
    for(auto [u,v,w]:adj){
        if(find(u)==find(v))continue;
        
        Union(u,v);
        cost+=w;
    }
    
    cout<<cost<<endl;
    
    
    return 0;
    
    
    
}