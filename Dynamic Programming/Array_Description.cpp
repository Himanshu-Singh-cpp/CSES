#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define inf 1e9
#define MOD (int)(1e9+7)
 
 
void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    // dp[i][j] -> number of subsequence at nth index if value at that index is j
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    if(arr[0] != 0)
        dp[0][arr[0]] = 1;
    else
        for(int i=1;i<=m;i++) dp[0][i] = 1;
    
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            for(int k=max(arr[i]-1,1LL);k<=min(arr[i]+1,m);k++){
                dp[i+1][k] = (dp[i+1][k] + dp[i][arr[i]])%MOD;
            }
        }
        else {
            for(int j=1;j<=m;j++){
                for(int k=max(j-1,1LL);k<=min(j+1,m);k++){
                    dp[i+1][k] = (dp[i+1][k] + dp[i][j])%MOD;
                }
            }
        }
    }
    
    if(arr[n-1] != 0)
        cout<<dp[n][arr[n-1]];
    else{
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans = (ans + dp[n-1][i])%MOD;
        }
        cout<<ans;
    }
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
}