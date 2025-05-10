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

    vector<int> dp(x+1,0);
    // dp[i] -> number of ordered ways to make i
    dp[0] = 1;
    for(int i=0;i<n;i++){
        // going element wise in array ensure no element is repeated more than it should be
        for(int j=1;j<=x;j++){
            if(j-arr[i] >= 0) dp[j] = (dp[j] + dp[j-arr[i]])%MOD;
        }
    }
    cout<<dp[x]<<'\n';
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
    
 
}
