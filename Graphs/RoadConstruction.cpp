#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

struct DSU{
    vector<int> par;
    int max_size;
    vector<int> size;
    int num_components;

    DSU(int n){
        par.resize(n);
        size.resize(n);
        iota(par.begin(),par.end(),0);
        for(int i=0;i<n;i++) size[i] = 1;
        max_size = 1;
        num_components = n;
    }

    int find_par(int x){
        if(x == par[x]) return x;
        return par[x] = find_par(par[x]);
    }

    void unite(int x, int y){
        x = find_par(x);
        y = find_par(y);
        if(x == y) return;
        num_components--;
        if(size[x] > size[y]){
            swap(x,y);
        }

        max_size = max(max_size,size[x] + size[y]);
        par[x] = y; // attach the one with small size to the bigger one 
        size[y] += size[x];
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    DSU dsu = DSU(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        dsu.unite(u,v);
        cout<<dsu.num_components<<' '<<dsu.max_size<<'\n';
    }


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