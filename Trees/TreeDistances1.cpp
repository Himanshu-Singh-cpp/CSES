#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node, int par, vector<vector<int>>& adj,vector<int>& dist){
    dist[node] = dist[par] + 1;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,adj,dist);
        }
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

    vector<int> distances(n+1,-1);
    dfs(1,0,adj,distances);
    int diamater_1 = distance(distances.begin(),max_element(distances.begin(),distances.end()));
    vector<int> dist1(n+1,-1);
    dfs(diamater_1,0,adj,dist1);
    int diameter_2 = distance(dist1.begin(),max_element(dist1.begin(),dist1.end()));
    vector<int> dist2(n+1,-1);
    dfs(diameter_2,0,adj,dist2);

    for(int i=1;i<=n;i++) cout<<max(dist1[i],dist2[i])<<' ';
        
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