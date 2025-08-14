#include<bits/stdc++.h>
using namespace std;
 
// #define int long long 
#define INF 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> dx = {1,0,0,-1};
    vector<int> dy = {0,1,-1,0};

    vector<string> mat(n);
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    pair<int,int> start;
    pair<int,int> end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 'A') start = {i,j};
            if(mat[i][j] == 'B') end = {i,j};
        }
    }
    map<pair<int,int>,pair<int,int>> par;
    bool found = false;

    queue<pair<int,int>> qu;
    qu.push(start);
    vector<vector<int>> vis(n,vector<int>(m,0));
    vis[start.first][start.second] = 1;
    while(!qu.empty()){
        pair<int,int> top = qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            int x = top.first + dx[i];
            int y = top.second + dy[i];
            if(!((x >= 0) && (x < n) && (y >= 0) && (y < m))){
                continue;
            }
            if(vis[x][y] == 1) continue;
            par[{x,y}] = top;
            if(mat[x][y] == '#') continue;
            if(mat[x][y] == 'B') found = true;
            vis[x][y] = 1;
            qu.push({x,y});
            if(found) break;
        }
        if(found) break;
    }

    if(!found){
        cout<<"NO\n";
        return;
    }
    vector<char> ans;
    pair<int,int> curr = end;
    while(curr != start){
        pair<int,int> curr_par = par[curr];
        if(curr_par.first + 1 == curr.first) ans.push_back('D');
        if(curr_par.first - 1 == curr.first) ans.push_back('U');
        if(curr_par.second + 1 == curr.second) ans.push_back('R');
        if(curr_par.second - 1 == curr.second) ans.push_back('L');
        curr = curr_par;
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES\n";
    cout<<ans.size()<<'\n';
    for(char it:ans) cout<<it;



}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin>>t;
    while (t--){
        solve();
    }
}