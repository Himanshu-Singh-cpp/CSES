#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define inf 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int a,b;
    cin>>a>>b;
    int bth = min(a,b);
    int len = max(a,b);

    vector<vector<int>> dp(bth+1,vector<int>(len+1,inf));
    for(int i=1;i<=bth;i++){
        for(int j=1;j<=len;j++){
            if(i == j) dp[i][j] = 0;
            else {
                for(int k=1;k<i;k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
                for(int k=1;k<j;k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
                if(j < bth) dp[j][i] = dp[i][j];
            }
        }
    }
    
    cout<<dp[bth][len];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
}
