//https://dmoj.ca/problem/dpd
//AKA 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, w; cin>>n>>w;

    vector<int>weight(n+1);
    vector<int>value(n+1);

    for(int i=1;i<=n;i++){
        cin>>weight[i];
        cin>>value[i];
    }

    vector<vector<int>>dp(2, vector<int>(w+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[1][j] = max(dp[0][j], dp[1][j-1]);
            if(j>=weight[i]){
                dp[1][j] = max(dp[1][j], value[i]+dp[0][j-weight[i]]);
            }
        }
        for(int i=1;i<=w;i++){
            dp[0][i] = dp[1][i];
        }
    }
    cout<<dp[0][w];


    return 0;
}