//https://dmoj.ca/problem/vmss7wc16c5p4
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, x, y, z;
    cin>>n>>x>>y>>z;

    vector<int>dp(n+1);
    vector<int>arr{0,x,y,z};
    dp[x] = 1;
    dp[y] = 1;
    dp[z] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(i-arr[j]>0 && dp[i-arr[j]]!=0){
                dp[i] = max(dp[i], dp[i-arr[j]]+1);
            }
        }
    }
    cout<<dp[n];
    return 0;
}