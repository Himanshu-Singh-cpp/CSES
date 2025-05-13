#include<bits/stdc++.h>
using namespace std;
 
// #define int long long 
#define inf 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    set<int> s;
    for(int i=0;i<n;i++){
        auto it1 = s.lower_bound(arr[i]);
        if(it1 != s.end()) s.erase(it1);
        s.insert(arr[i]);
    }
    cout<<s.size();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
}
