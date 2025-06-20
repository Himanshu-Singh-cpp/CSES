#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void dfs(int node,int par,vector<vector<int>>& adj,vector<vector<int>>& arr, int level){
    arr[node][0] = par;
    for(int i=1;i<=level;i++){
        int midway = arr[node][i-1];
        arr[node][i] = arr[midway][i-1];
    }
    for(auto it:adj[node]){
        if(it != par) dfs(it,node,adj,arr,level);
    }
}

void solve(){
    int n,q;
    cin>>n>>q;

    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){
        int u;
        cin>>u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    int level = 0;
    int num = 1;
    while(num < n){
        num*= 2;
        level++;
    }

    vector<vector<int>> arr(n+1,vector<int>(level+1,0));
    dfs(1,0,adj,arr,level);

    while(q--){
        int x,k;
        cin>>x>>k;
        if(k > n) cout<<"-1\n";
        else {
            int curr = x;
            for(int i=0;i<=level;i++){
                if(((k>>i)&1) == 1) curr = arr[curr][i];
            }
            if (curr == 0) cout<<"-1\n";
            else cout<<curr<<"\n";
        }
    }

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