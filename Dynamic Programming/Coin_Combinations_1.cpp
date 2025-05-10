#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define inf 1e9
#define MOD (int)(1e9+7)
 
 
void solve(){
    int n,x;
    cin>>n>>x;;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // dp state is distinct ways you can produce a money sum i 
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-arr[j] >= 0) dp[i] =  (dp[i] + dp[i-arr[j]])%MOD;
        }
    }
    if(dp[x] == inf) cout<<"-1\n";
    else cout<<dp[x]<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
    
 
}
