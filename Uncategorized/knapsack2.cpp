//https://dmoj.ca/problem/dpe
//AKA 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, w; cin>>n>>w;
    vector<int>weight(n+1);
    vector<int>value(n+1);
    int s=0;
    int ans = 0;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
        cin>>value[i];
        s+=value[i];
    }
    vector<vector<int>>dp(2, vector<int>(s+1));
    for(int i=1;i<=s;i++) dp[0][i] = 1e18;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            dp[1][j] = dp[0][j];
            if(j>=value[i]) dp[1][j] = min(dp[1][j], weight[i]+dp[0][j-value[i]]);
            if(dp[1][j]<=w)ans = max(ans, j);
        }
        for(int j=1;j<=s;j++) dp[0][j] = dp[1][j];
    }
    cout<<ans;
    return 0;
}