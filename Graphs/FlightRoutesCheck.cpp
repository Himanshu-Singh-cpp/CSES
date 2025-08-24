#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0) dfs(it,vis,adj);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<int> vis(n,0);
    dfs(0,vis,adj);
    for(int i=1;i<n;i++){
        if(vis[i] == 0){
            cout<<"NO\n";
            cout<<1<<' '<<(i+1);
            return;
        }
    }

    fill(vis.begin(),vis.end(),0);
    dfs(0,vis,rev_adj);
    for(int i=1;i<n;i++){
        if(vis[i] == 0){
            cout<<"NO\n";
            cout<<(i+1)<<' '<<1;
            return;
        }
    }
    cout<<"YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    // cin >> t;
    while(t--){
        solve();
    }
}