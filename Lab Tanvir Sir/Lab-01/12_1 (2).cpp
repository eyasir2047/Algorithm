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