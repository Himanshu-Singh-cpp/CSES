#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

int dfs_children(int node,int par,vector<vector<int>>&adj,vector<int>&children){
    int ans = 0;
    for(auto it: adj[node]){
        if(it != par){
            ans += 1+dfs_children(it,node,adj,children);
        }
    }
    children[node] = ans;
    return ans;
}

int dfs_sum_dist(int node, int par,vector<vector<int>>& adj,vector<int>& children){
    int ans = children[node];
    for(auto it: adj[node]){
        if(it != par){
            ans += dfs_sum_dist(it,node,adj,children);
        }
    }
    return ans;
}

void dfs(int node, int par, vector<vector<int>>& adj,vector<int>& answer,vector<int>& children,int n){
    if(answer[node] == -1) answer[node] = answer[par] - (children[node]) + (n-children[node] - 2);
    for(auto it: adj[node]){
        if(it != par) dfs(it,node,adj,answer,children,n);
    }
}


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> children(n+1,0);
    dfs_children(1,0,adj,children);
    vector<int> ans(n+1,-1);
    ans[1] = dfs_sum_dist(1,0,adj,children);
    dfs(1,0,adj,ans,children,n);
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';

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