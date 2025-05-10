#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define inf 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    string s1,s2;
    cin>>s1>>s2;

    int n1 = s1.length();
    int n2 = s2.length();

    // dp[i][j] -> steps to convert s1[:i] to s2[:j]
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,inf));

    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if((i == 0) && (j == 0)) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = dp[i][j-1] + 1;
            else if (j == 0) dp[i][j] = dp[i-1][j] + 1;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
    }
    cout<<dp[n1][n2];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
    
 
}
