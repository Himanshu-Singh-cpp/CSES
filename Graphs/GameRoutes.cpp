#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int>& order){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0) {
            dfs(it,vis,adj,order);
        }
    }
    order.push_back(node);
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
    }

    vector<int> vis(n,0);
    vector<int> order;
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            dfs(i,vis,adj,order);
        }
    }


    vector<int> dp(n,0);
    dp[0] = 1;
    for(int i=n-1;i>=0;i--){
        for(auto it:adj[order[i]]){
            dp[it] += dp[order[i]];
            dp[it] %= MOD;
        }
    }
    cout<<dp[n-1];




}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}