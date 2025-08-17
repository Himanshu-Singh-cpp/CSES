#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e15
#define MOD (int)(1e9+7)


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<pair<int,int>>> rev_adj(n);

    for(int i=0;i<m;i++){
        int  a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back({b,c});
        rev_adj[b].push_back({a,c});
    }
    vector<int> dist_source(n,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist_source[0] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        if(curr_dist > dist_source[node]) continue;
        for(auto it: adj[node]){
            if(it.second + curr_dist < dist_source[it.first]){
                dist_source[it.first] = it.second + curr_dist;
                pq.push({it.second + curr_dist, it.first});
            }
        }
    }
    
    vector<int> dist_dest(n,INF);
    dist_dest[n-1] = 0;
    pq.push({0, n-1});
    
    while(!pq.empty()){
        int node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        if(curr_dist > dist_dest[node]) continue;
        for(auto it: rev_adj[node]){
            if(it.second + curr_dist < dist_dest[it.first]){
                dist_dest[it.first] = it.second+ curr_dist;
                pq.push({it.second + curr_dist, it.first});
            }
        }
    }


    int ans = INF;
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            ans = min(ans,dist_source[i] + (it.second/2) + dist_dest[it.first]);
        }
    }
    cout<<ans;



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