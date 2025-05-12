#include<bits/stdc++.h>
using namespace std;
 
// #define int long long 
#define inf 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n,x; // n -> number of books // x -> maximum total price
    cin>>n>>x;

    vector<int> prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    vector<int> pages(n);
    for(int i=0;i<n;i++) cin>>pages[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    // dp[i][j] -> at the ith index if we have used j coins what's the max pages we could get
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            if(j < prices[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-prices[i]] + pages[i]);
        }
    }

    cout<<dp[n][x];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
}
