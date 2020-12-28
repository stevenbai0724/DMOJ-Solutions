//https://dmoj.ca/problem/avatarbalance
#include <bits/stdc++.h>
using namespace std;
#define int double
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    int s = 0;
    int w = 0;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        s+=arr[i];
    }
    w = s/2;

    vector<vector<int>>dp(2, vector<int>(w+1));

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[1][j] = max(dp[0][j], dp[1][j-1]);
            if(j>=arr[i]){
                dp[1][j] = max(dp[1][j], arr[i]+dp[0][j-arr[i]]);
            }
        }
        for(int i=1;i<=w;i++){
            dp[0][i] = dp[1][i];
        }
    }
    cout<<(w-dp[0][w])*2;


    return 0;
}