#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> qu;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0) {
            qu.push(i);
        }
    }

    vector<int> ans;
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            if(indegree[it] > 0){
                indegree[it]--;
                if(indegree[it] == 0) qu.push(it);
            }
        }
    }

    if(ans.size() != n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(int i=0;i<n;i++) cout<<(ans[i]+1)<<' ';
    
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