#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define inf 1e9
#define MOD (int)(1e9+7)
 
void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
 
    // dp[i+1][j+1] -> longest common subsequence of arr[i] and arr2[j]
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            if(arr1[i] == arr2[j]) dp[i+1][j+1] = dp[i][j] + 1;
        }
    }
    int ind1 = n;
    int ind2 = m;
    vector<int> ans;
    while(ind1 > 0 && ind2 > 0){
        if(arr1[ind1 - 1] == arr2[ind2 - 1]){
            ans.push_back(arr1[--ind1]);
            ind2--;
        } else if(dp[ind1 - 1][ind2] >= dp[ind1][ind2 - 1]){
            ind1--;
        } else {
            ind2--;
        }
    }

    cout<<dp[n][m]<<'\n';
    for(int i= ans.size() -1;i>=0;i--) cout<<ans[i]<<' ';
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while (t--){
        solve();
    }
    
 
}
